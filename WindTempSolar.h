#ifndef WINDTEMPSOLAR_H
#define WINDTEMPSOLAR_H

#include "Date.h"
#include "Time.h"
#include <string>

/**
 * @brief Class to represent weather data including wind speed, temperature, and solar radiation.
 *
 * This class represents weather data for a specific date and time, including wind speed,
 * ambient temperature, and solar radiation.
 */
class WindTempSolar {
public:
    /**
     * @brief Default constructor.
     *
     * Constructs a WindTempSolar object with default values.
     */
    WindTempSolar();

    /**
     * @brief Constructs a WindTempSolar object with specified parameters.
     *
     * Constructs a WindTempSolar object with the provided date, time, wind speed, temperature,
     * and solar radiation values.
     *
     * @param date The date of the weather data.
     * @param time The time of the weather data.
     * @param wind_speed The wind speed in meters per second.
     * @param temperature The ambient temperature in degrees Celsius.
     * @param solar_radiation The solar radiation in MegaJoules per square meter.
     */
    WindTempSolar(const Date& date, const Time& time, float wind_speed, float temperature, float solar_radiation);

    /**
     * @brief Gets the date of the weather data.
     *
     * @return The date of the weather data.
     */
    Date getDate() const;

    /**
     * @brief Sets the date of the weather data.
     *
     * @param date The date to set.
     */
    void setDate(const Date& date);

    /**
     * @brief Gets the time of the weather data.
     *
     * @return The time of the weather data.
     */
    Time getTime() const;

    /**
     * @brief Sets the time of the weather data.
     *
     * @param time The time to set.
     */
    void setTime(const Time& time);

    /**
     * @brief Gets the wind speed.
     *
     * @return The wind speed in meters per second.
     */
    float getWindSpeed() const;

    /**
     * @brief Sets the wind speed.
     *
     * @param wind_speed The wind speed to set in meters per second.
     */
    void setWindSpeed(float wind_speed);

    /**
     * @brief Gets the ambient temperature.
     *
     * @return The ambient temperature in degrees Celsius.
     */
    float getTemperature() const;

    /**
     * @brief Sets the ambient temperature.
     *
     * @param temperature The ambient temperature to set in degrees Celsius.
     */
    void setTemperature(float temperature);

    /**
     * @brief Gets the solar radiation.
     *
     * @return The solar radiation in MegaJoules per square meter.
     */
    float getSolarRadiation() const;

    /**
     * @brief Sets the solar radiation.
     *
     * @param solar_radiation The solar radiation to set in MegaJoules per square meter.
     */
    void setSolarRadiation(float solar_radiation);

    /**
    * @brief Retrieve the value of a specific field from the WindTempSolar object.
    *
    * This function retrieves the value of a specified field from the WindTempSolar object.
    * Valid field names are "wind_speed", "temperature", and "solar_radiation".
    *
    * @param field The name of the field whose value is to be retrieved.
    * @return The value of the specified field, or 0.0 if the field name is not recognized.
    */
    float getValue(const std::string& field) const;

    /**
     * @brief Overload less than operator.
     *
     * Compares two WindTempSolar objects based on wind speed, temperature, and solar radiation.
     *
     * @param other The other WindTempSolar object to compare with.
     * @return True if this object is less than the other, false otherwise.
     */
    bool operator<(const WindTempSolar& other) const;

    /**
     * @brief Overload greater than operator.
     *
     * Compares two WindTempSolar objects based on wind speed, temperature, and solar radiation.
     *
     * @param other The other WindTempSolar object to compare with.
     * @return True if this object is greater than the other, false otherwise.
     */
    bool operator>(const WindTempSolar& other) const;

    /**
     * @brief Input data for the WindTempSolar object.
     *
     * Sets the data for the WindTempSolar object including date, time, wind speed,
     * ambient temperature, and solar radiation.
     *
     * @param date The date of the weather data.
     * @param time The time of the weather data.
     * @param wind_speed The wind speed in meters per second.
     * @param temperature The ambient temperature in degrees Celsius.
     * @param solar_radiation The solar radiation in MegaJoules per square meter.
     */
    void inputData(const Date& date, const Time& time, float wind_speed, float temperature, float solar_radiation);

private:
    Date date;                  /**< The date of the weather data. */
    Time time;                  /**< The time of the weather data. */
    float wind_speed;           /**< The wind speed in meters per second. */
    float temperature;          /**< The ambient temperature in degrees Celsius. */
    float solar_radiation;      /**< The solar radiation in MegaJoules per square meter. */
};

#endif // WINDTEMPSOLAR_H
