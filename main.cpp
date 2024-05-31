#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <map>
#include "Date.h"
#include "Time.h"
#include "CalcResults.h"
#include "WindTempSolar.h"
#include "DataProcessor.h"
#include "Vector.h"
#include "Bst.h"

// Function to print data to a file
template <class T>
void printDataToFile(const std::string& filename, const std::string& data) {
    // Open the output file
    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        // Write data to the file
        outFile << data;
        // Close the file
        outFile.close();
        // Print success message
        std::cout << "Data has been written to " << filename << std::endl;
    } else {
        // Print error message if unable to open the file
        std::cerr << "Unable to open file " << filename << " for writing." << std::endl;
    }
}

int main() {
    // Read data source file names from data_source.txt
    std::ifstream sourceFile("data/data_source.txt"); // Assuming data_source.txt is in the 'data' folder
    Vector<std::string> fileNames; // Vector to store file names
    std::string fileName;
    if (sourceFile.is_open()) {
        // Read each file name from the data_source.txt and store in the vector
        while (std::getline(sourceFile, fileName)) {
    if (!fileName.empty()) { // Check if fileName is not empty
        fileNames.push_back("data/" + fileName);
    }
}

        // Close the data_source.txt file
        sourceFile.close();
    } else {
        // Print error message if unable to open data_source.txt
        std::cerr << "Unable to open data/data_source.txt" << std::endl;
        return 1;
    }

    // Declare WindTempSolar objects
    Vector<WindTempSolar> windTempSolarVector;
    Bst<WindTempSolar> windTempSolarBst;
    std::map<std::string, WindTempSolar> windTempSolarMap;

    // Perform in-order traversal on the BST and calculate the sum of wind speeds
    windTempSolarBst.inOrderTraversal(&DataProcessor::calculateWindSpeedCallback);
    windTempSolarBst.inOrderTraversal(&DataProcessor::calculateTemperatureCallback);

    // Process each file
    for (size_t i = 0; i < fileNames.size(); ++i) {
        const auto& currentFileName = fileNames[i];
        // Read data from file
        std::ifstream file(currentFileName);
        if (file.is_open()) {
            std::string line;
            std::getline(file, line); // Skip the header line

            // Parse each line of the file
            while (std::getline(file, line)) {
                std::stringstream ss(line);
                std::string date, time;
                float wind_speed, temperature, solar_radiation;

                // Extract data from the line
                std::getline(ss, date, ',');
                std::getline(ss, time, ',');
                ss >> wind_speed;
                ss.ignore(); // Ignore the comma
                ss >> temperature;
                ss.ignore(); // Ignore the comma
                ss >> solar_radiation;

                // Create WindTempSolar record
                WindTempSolar record = {Date(date), Time(time), wind_speed, temperature, solar_radiation};

                // Insert into Vector
                windTempSolarVector.push_back(record);

                // Insert into Bst
                windTempSolarBst.insert(record);

                // Insert into Map (using date as key)
                windTempSolarMap[date] = record;

            }
            // Close the file
            file.close();
        } else {
            // Print error message if unable to open the file
            std::cerr << "Unable to open file " << currentFileName << std::endl;
            // Continue with next file or handle error as needed
        }
    }
    // Create calculator object
    CalcResults calculator(windTempSolarVector, windTempSolarBst, windTempSolarMap);


    int choice;
    do {
        // Display menu
        std::cout << "Menu:\n"
                  << "1. Average Wind Speed and sample standard deviation for specified month and year\n"
                  << "2. Average Ambient Air Temperature and sample standard deviation for each month of specified year\n"
                  << "3. Sample Pearson Correlation Coefficient for specified month\n"
                  << "4. Average Wind Speed, Ambient Air Temperature, and Total Solar Radiation for each month of specified year\n"
                  << "5. Exit\n"
                  << "Enter your choice: ";
        // Get user choice
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int month, year;
                std::cout << "Enter month and year (MM YYYY): ";
                std::cin >> month >> year;
                // Calculate and display average wind speed and sample standard deviation
                float avgWindSpeed = calculator.calculateAverageWindSpeed(month, year);
                float stdDev = calculator.calculateStandardDeviation(month, year);
                std::cout << "Average Wind Speed for " << month << "/" << year << ": " << avgWindSpeed << " m/s" << std::endl;
                std::cout << "Sample Standard Deviation for " << month << "/" << year << ": " << stdDev << " m/s" << std::endl;
                break;
            }
            case 2: {
                int year;
                std::cout << "Enter year (YYYY): ";
                std::cin >> year;
                // Calculate and display average ambient air temperature and sample standard deviation for each month
                for (int month = 1; month <= 12; ++month) {
                    float avgTemp = calculator.calculateAverageAmbientTemperature(month, year);
                    float stdDev = calculator.calculateStandardDeviation(month, year);
                    std::cout << "Average Ambient Air Temperature for " << month << "/" << year << ": " << avgTemp << " °C" << std::endl;
                    std::cout << "Sample Standard Deviation for " << month << "/" << year << ": " << stdDev << " °C" << std::endl;
                }
                break;
            }
            case 3: {
                int month;
                std::cout << "Enter month (1-12): ";
                std::cin >> month;
                std::cout << "Sample Pearson Correlation Coefficient for " << month << std::endl;

                // Calculate SPCC for each combination
                float spcc_ST = calculator.calculateSPCC(month, "wind_speed", "temperature");
                float spcc_SR = calculator.calculateSPCC(month, "wind_speed", "solar_radiation");
                float spcc_TR = calculator.calculateSPCC(month, "temperature", "solar_radiation");

                // Display the results
                std::cout << "S_T: " << spcc_ST << std::endl;
                std::cout << "S_R: " << spcc_SR << std::endl;
                std::cout << "T_R: " << spcc_TR << std::endl;
                break;
            }
            case 4: {
                int year;
                std::cout << "Enter year (YYYY): ";
                std::cin >> year;
                std::stringstream output;
                output << std::fixed << std::setprecision(2); // Set precision for floating-point output
                output << "Month, Average Wind Speed (km/h) (stdev, mad), Average Ambient Air Temperature (°C) (stdev, mad), Total Solar Radiation (kWh/m^2)\n";

                // Calculate and format data for each month and write to output stringstream
                for (int month = 1; month <= 12; ++month) {
                    float avgWindSpeed = calculator.calculateAverageWindSpeed(month, year);
                    float windSpeedStdev = calculator.calculateStandardDeviation(month, year);
                    float windSpeedMAD = calculator.calculateWindSpeedMAD(month, year);

                    float avgTemp = calculator.calculateAverageAmbientTemperature(month, year);
                    float tempStdev = calculator.calculateStandardDeviation(month, year); // Change to calculateStandardDeviation(month, year)
                    float tempMAD = calculator.calculateTemperatureMAD(month, year); // Change to calculateTemperatureMAD(month, year)

                    float totalRadiation = calculator.calculateTotalSolarRadiation(month, year);

                    output << month << ", "
                           << avgWindSpeed << " (" << windSpeedStdev << ", " << windSpeedMAD << "), "
                           << avgTemp << " (" << tempStdev << ", " << tempMAD << "), "
                           << totalRadiation << "\n";
                }

                std::string filename = "data/WindTempSolar.csv"; // Output file
                // Call the function to print data to the file
                printDataToFile<Vector<std::string>>(filename, output.str());
                break;
            }

            case 5:
                // Exit program
                std::cout << "Exiting program." << std::endl;
                break;
            default:
                // Invalid choice
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 5);

    return 0;
}

