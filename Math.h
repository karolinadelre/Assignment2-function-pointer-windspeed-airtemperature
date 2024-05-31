#ifndef MATH_H
#define MATH_H

#include "Vector.h"
#include "WindTempSolar.h"
#include <cmath>
#include <string>

/**
 * @brief The Math class provides static methods for various calculations based on wind, temperature, and solar data.
 */
class Math {
public:
    /**
     * @brief Calculate and return the average wind speed for the specified month and year.
     * @param data Vector of WindTempSolar objects containing the data.
     * @param month The month for which to calculate the average wind speed.
     * @param year The year for which to calculate the average wind speed.
     * @return The average wind speed for the specified month and year.
     */
    static float calculateAverageWindSpeed(const Vector<WindTempSolar>& data, int month, int year);

    /**
     * @brief Calculate and return the standard deviation of wind speed for the specified month and year.
     * @param data Vector of WindTempSolar objects containing the data.
     * @param month The month for which to calculate the standard deviation of wind speed.
     * @param year The year for which to calculate the standard deviation of wind speed.
     * @return The standard deviation of wind speed for the specified month and year.
     */
    static float calculateStandardDeviation(const Vector<WindTempSolar>& data, int month, int year);

    /**
     * @brief Calculate and return the average ambient air temperature for the specified month and year.
     * @param data Vector of WindTempSolar objects containing the data.
     * @param month The month for which to calculate the average ambient air temperature.
     * @param year The year for which to calculate the average ambient air temperature.
     * @return The average ambient air temperature for the specified month and year.
     */
    static float calculateAverageAmbientTemperature(const Vector<WindTempSolar>& data, int month, int year);

    /**
     * @brief Calculate and return the total solar radiation for the specified month and year.
     * @param data Vector of WindTempSolar objects containing the data.
     * @param month The month for which to calculate the total solar radiation.
     * @param year The year for which to calculate the total solar radiation.
     * @return The total solar radiation for the specified month and year.
     */
    static float calculateTotalSolarRadiation(const Vector<WindTempSolar>& data, int month, int year);

    /**
     * @brief Calculate and return the mean absolute deviation of wind speed for the specified month and year.
     * @param data Vector of WindTempSolar objects containing the data.
     * @param month The month for which to calculate the mean absolute deviation of wind speed.
     * @param year The year for which to calculate the mean absolute deviation of wind speed.
     * @return The mean absolute deviation of wind speed for the specified month and year.
     */
    static float calculateWindSpeedMAD(const Vector<WindTempSolar>& data, int month, int year);

    /**
     * @brief Calculate and return the mean absolute deviation of temperature for the specified month and year.
     * @param data Vector of WindTempSolar objects containing the data.
     * @param month The month for which to calculate the mean absolute deviation of temperature.
     * @param year The year for which to calculate the mean absolute deviation of temperature.
     * @return The mean absolute deviation of temperature for the specified month and year.
     */
    static float calculateTemperatureMAD(const Vector<WindTempSolar>& data, int month, int year);

    /**
     * @brief Calculate and return the sample Pearson correlation coefficient (SPCC) between two fields for the specified month.
     * @param data Vector of WindTempSolar objects containing the data.
     * @param month The month for which to calculate the SPCC.
     * @param field1 The field representing the first variable (e.g., "wind_speed").
     * @param field2 The field representing the second variable (e.g., "temperature").
     * @return The sample Pearson correlation coefficient (SPCC) between the two fields for the specified month.
     */
    static float calculateSPCC(const Vector<WindTempSolar>& data, int month, const std::string& field1, const std::string& field2);
};

#endif // MATH_H
