#include "Math.h"

// Calculates and returns the average wind speed for the specified month and year.
float Math::calculateAverageWindSpeed(const Vector<WindTempSolar>& data, int month, int year) {
    float sum = 0;
    int count = 0;
    // Iterate over the data vector to calculate the sum and count of wind speeds
    for (int i = 0; i < data.size(); ++i) {
        const WindTempSolar& record = data[i];
        // Check if the record's date matches the specified month and year
        if (record.getDate().getMonth() == month && record.getDate().getYear() == year) {
            sum += record.getWindSpeed();
            count++;
        }
    }
    // Return the average wind speed or 0 if no records were found
    return (count > 0) ? sum / count : 0;
}


// Calculates and returns the standard deviation of wind speed for the specified month and year.
float Math::calculateStandardDeviation(const Vector<WindTempSolar>& data, int month, int year) {
    float mean = calculateAverageWindSpeed(data, month, year);
    float sumSquaredDiff = 0;
    int count = 0;
    // Iterate over the data vector to calculate the sum of squared differences
    for (int i = 0; i < data.size(); ++i) {
        const WindTempSolar& record = data[i];
        // Check if the record's date matches the specified month and year
        if (record.getDate().getMonth() == month && record.getDate().getYear() == year) {
            sumSquaredDiff += pow(record.getWindSpeed() - mean, 2);
            count++;
        }
    }
    // Calculate the variance and return the standard deviation
    float variance = (count > 0) ? sumSquaredDiff / count : 0;
    return sqrt(variance);
}

// Calculates and returns the average ambient air temperature for the specified month and year.
float Math::calculateAverageAmbientTemperature(const Vector<WindTempSolar>& data, int month, int year) {
    float sum = 0;
    int count = 0;
    // Iterate over the data vector to calculate the sum and count of temperatures
    for (int i = 0; i < data.size(); ++i) {
        const WindTempSolar& record = data[i];
        // Check if the record's date matches the specified month and year
        if (record.getDate().getMonth() == month && record.getDate().getYear() == year) {
            sum += record.getTemperature();
            count++;
        }
    }
    // Return the average temperature or 0 if no records were found
    return (count > 0) ? sum / count : 0;
}

// Calculates and returns the total solar radiation for the specified month and year.
float Math::calculateTotalSolarRadiation(const Vector<WindTempSolar>& data, int month, int year) {
    float total = 0;
    // Iterate over the data vector to calculate the total solar radiation
    for (int i = 0; i < data.size(); ++i) {
        const WindTempSolar& record = data[i];
        // Check if the record's date matches the specified month and year
        if (record.getDate().getMonth() == month && record.getDate().getYear() == year) {
            total += record.getSolarRadiation();
        }
    }
    // Return the total solar radiation
    return total;
}

// Calculates and returns the mean absolute deviation of wind speed for the specified month and year.
float Math::calculateWindSpeedMAD(const Vector<WindTempSolar>& data, int month, int year) {
    float mean = calculateAverageWindSpeed(data, month, year);
    float sumAbsoluteDifferences = 0;
    int count = 0;
    // Iterate over the data vector to calculate the sum of absolute differences
    for (int i = 0; i < data.size(); ++i) {
        const WindTempSolar& record = data[i];
        // Check if the record's date matches the specified month and year
        if (record.getDate().getMonth() == month && record.getDate().getYear() == year) {
            sumAbsoluteDifferences += std::abs(record.getWindSpeed() - mean);
            count++;
        }
    }
    // Return the mean absolute deviation or 0 if no records were found
    return (count > 0) ? sumAbsoluteDifferences / count : 0;
}

// Calculates and returns the mean absolute deviation of temperature for the specified month and year.
float Math::calculateTemperatureMAD(const Vector<WindTempSolar>& data, int month, int year) {
    float mean = calculateAverageAmbientTemperature(data, month, year);
    float sumAbsoluteDifferences = 0;
    int count = 0;
    // Iterate over the data vector to calculate the sum of absolute differences
    for (int i = 0; i < data.size(); ++i) {
        const WindTempSolar& record = data[i];
        // Check if the record's date matches the specified month and year
        if (record.getDate().getMonth() == month && record.getDate().getYear() == year) {
            sumAbsoluteDifferences += std::abs(record.getTemperature() - mean);
            count++;
        }
    }
    // Return the mean absolute deviation or 0 if no records were found
    return (count > 0) ? sumAbsoluteDifferences / count : 0;
}

// Calculates and returns the sample Pearson correlation coefficient (SPCC) between two fields for the specified month.
float Math::calculateSPCC(const Vector<WindTempSolar>& data, int month, const std::string& field1, const std::string& field2) {
    // Initialize variables for summation
    float sumField1 = 0;
    float sumField2 = 0;
    float sumField1Field2 = 0;
    float sumField1Squared = 0;
    float sumField2Squared = 0;
    int count = 0;

    // Iterate through the data vector
    for (int i = 0; i < data.size(); ++i) {
        const WindTempSolar& record = data[i];
        // Check if the record's date matches the specified month
        if (record.getDate().getMonth() == month) {
            // Extract the values of the specified fields
            float value1 = 0;
            float value2 = 0;
            if (field1 == "wind_speed") {
                value1 = record.getWindSpeed();
            } else if (field1 == "temperature") {
                value1 = record.getTemperature();
            } else if (field1 == "solar_radiation") {
                value1 = record.getSolarRadiation();
            }
            if (field2 == "wind_speed") {
                value2 = record.getWindSpeed();
            } else if (field2 == "temperature") {
                value2 = record.getTemperature();
            } else if (field2 == "solar_radiation") {
                value2 = record.getSolarRadiation();
            }

            // Update summation variables
            sumField1 += value1;
            sumField2 += value2;
            sumField1Field2 += value1 * value2;
            sumField1Squared += value1 * value1;
            sumField2Squared += value2 * value2;
            count++;
        }
    }

    // Check if no records were found for the specified month
    if (count == 0) return 0;

    // Calculate the numerator and denominator of the correlation coefficient formula
    float numerator = count * sumField1Field2 - sumField1 * sumField2;
    float denominator = std::sqrt((count * sumField1Squared - sumField1 * sumField1) * (count * sumField2Squared - sumField2 * sumField2));

    // Calculate and return the correlation coefficient (avoid division by zero)
    return (denominator != 0) ? numerator / denominator : 0;
}
