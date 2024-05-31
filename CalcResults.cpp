#include "CalcResults.h"
#include "Math.h"

// Constructor for CalcResults, initializes the object with data from the provided vector, BST, and map.
CalcResults::CalcResults(const Vector<WindTempSolar>& data, const Bst<WindTempSolar>& bstData, const std::map<std::string, WindTempSolar>& dataMap)
    : data(data), bstData(bstData), dataMap(dataMap) {}

// Calculates and returns the average wind speed for the specified month and year.
float CalcResults::calculateAverageWindSpeed(int month, int year) const {
    return Math::calculateAverageWindSpeed(data, month, year);
}

// Calculates and returns the standard deviation of wind speed for the specified month and year.
float CalcResults::calculateStandardDeviation(int month, int year) const {
    return Math::calculateStandardDeviation(data, month, year);
}

// Calculates and returns the average ambient air temperature for the specified month and year.
float CalcResults::calculateAverageAmbientTemperature(int month, int year) const {
    return Math::calculateAverageAmbientTemperature(data, month, year);
}

// Calculates and returns the total solar radiation for the specified month and year.
float CalcResults::calculateTotalSolarRadiation(int month, int year) const {
    return Math::calculateTotalSolarRadiation(data, month, year);
}

// Calculates and returns the mean absolute deviation of wind speed for the specified month and year.
float CalcResults::calculateWindSpeedMAD(int month, int year) const {
    return Math::calculateWindSpeedMAD(data, month, year);
}

// Calculates and returns the mean absolute deviation of temperature for the specified month and year.
float CalcResults::calculateTemperatureMAD(int month, int year) const {
    return Math::calculateTemperatureMAD(data, month, year);
}

// Calculates and returns the sample Pearson correlation coefficient (SPCC) between two fields for the specified month.
float CalcResults::calculateSPCC(int month, const std::string& field1, const std::string& field2) const {
    return Math::calculateSPCC(data, month, field1, field2);
}
