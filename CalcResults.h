#ifndef CALCRESULTS_H
#define CALCRESULTS_H

#include "Vector.h"
#include "Bst.h"
#include "WindTempSolar.h"
#include "Math.h"
#include <map>

/**
 * @brief The CalcResults class provides functionality to calculate various results based on wind, temperature, and solar data.
 *
 * This class calculates statistics such as average wind speed, standard deviation, mean absolute deviation, total solar radiation, and sample Pearson correlation coefficient (SPCC).
 */
class CalcResults {
public:
    /**
     * @brief Constructor for CalcResults.
     * @param data Vector of WindTempSolar objects containing the data.
     * @param bstData Binary search tree of WindTempSolar objects containing the data.
     * @param dataMap Map with date strings as keys and corresponding WindTempSolar objects as values.
     */
    CalcResults(const Vector<WindTempSolar>& data, const Bst<WindTempSolar>& bstData, const std::map<std::string, WindTempSolar>& dataMap);

    /**
     * @brief Calculate and return the average wind speed for the specified month and year.
     * @param month The month for which to calculate the average wind speed.
     * @param year The year for which to calculate the average wind speed.
     * @return The average wind speed for the specified month and year.
     */
    float calculateAverageWindSpeed(int month, int year) const;

    /**
     * @brief Calculate and return the standard deviation of wind speed for the specified month and year.
     * @param month The month for which to calculate the standard deviation of wind speed.
     * @param year The year for which to calculate the standard deviation of wind speed.
     * @return The standard deviation of wind speed for the specified month and year.
     */
    float calculateStandardDeviation(int month, int year) const;

    /**
     * @brief Calculate and return the average ambient air temperature for the specified month and year.
     * @param month The month for which to calculate the average ambient air temperature.
     * @param year The year for which to calculate the average ambient air temperature.
     * @return The average ambient air temperature for the specified month and year.
     */
    float calculateAverageAmbientTemperature(int month, int year) const;

    /**
     * @brief Calculate and return the total solar radiation for the specified month and year.
     * @param month The month for which to calculate the total solar radiation.
     * @param year The year for which to calculate the total solar radiation.
     * @return The total solar radiation for the specified month and year.
     */
    float calculateTotalSolarRadiation(int month, int year) const;

    /**
     * @brief Calculate and return the mean absolute deviation of wind speed for the specified month and year.
     * @param month The month for which to calculate the mean absolute deviation of wind speed.
     * @param year The year for which to calculate the mean absolute deviation of wind speed.
     * @return The mean absolute deviation of wind speed for the specified month and year.
     */
    float calculateWindSpeedMAD(int month, int year) const;

    /**
     * @brief Calculate and return the mean absolute deviation of temperature for the specified month and year.
     * @param month The month for which to calculate the mean absolute deviation of temperature.
     * @param year The year for which to calculate the mean absolute deviation of temperature.
     * @return The mean absolute deviation of temperature for the specified month and year.
     */
    float calculateTemperatureMAD(int month, int year) const;

    /**
     * @brief Calculate and return the sample Pearson correlation coefficient (SPCC) between wind speed and temperature for the specified month and year.
     * @param month The month for which to calculate the SPCC.
     * @param field1 The field representing the first variable (e.g., "wind_speed").
     * @param field2 The field representing the second variable (e.g., "temperature").
     * @return The sample Pearson correlation coefficient (SPCC) between wind speed and temperature for the specified month.
     */
    float calculateSPCC(int month, const std::string& field1, const std::string& field2) const;

private:
    const Vector<WindTempSolar>& data; /**< Vector of WindTempSolar objects containing the data. */
    const Bst<WindTempSolar>& bstData; /**< Binary search tree of WindTempSolar objects containing the data. */
    const std::map<std::string, WindTempSolar>& dataMap; /**< Map with date strings as keys and corresponding WindTempSolar objects as values. */
};

#endif // CALCRESULTS_H

