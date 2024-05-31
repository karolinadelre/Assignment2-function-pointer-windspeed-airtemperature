#include "WindTempSolar.h"
#include "CalcResults.h"

// Default constructor initializes all member variables to zero
WindTempSolar::WindTempSolar() : wind_speed(0), temperature(0), solar_radiation(0) {}

// Constructor initializes WindTempSolar with provided date, time, wind speed, temperature, and solar radiation
WindTempSolar::WindTempSolar(const Date& date, const Time& time, float wind_speed, float temperature, float solar_radiation)
    : date(date), time(time), wind_speed(wind_speed), temperature(temperature), solar_radiation(solar_radiation) {}

// Function to input data for WindTempSolar object
void WindTempSolar::inputData(const Date& date, const Time& time, float wind_speed, float temperature, float solar_radiation) {
    // Set data for WindTempSolar object
    setDate(date);
    setTime(time);
    setWindSpeed(wind_speed);
    setTemperature(temperature);
    setSolarRadiation(solar_radiation);
}
// Getter function for retrieving the date
Date WindTempSolar::getDate() const {
    return date;
}

// Setter function for setting the date
void WindTempSolar::setDate(const Date& date) {
    this->date = date;
}

// Getter function for retrieving the time
Time WindTempSolar::getTime() const {
    return time;
}

// Setter function for setting the time
void WindTempSolar::setTime(const Time& time) {
    this->time = time;
}

// Getter function for retrieving the wind speed
float WindTempSolar::getWindSpeed() const {
    return wind_speed;
}

// Setter function for setting the wind speed
void WindTempSolar::setWindSpeed(float wind_speed) {
    this->wind_speed = wind_speed;
}

// Getter function for retrieving the temperature
float WindTempSolar::getTemperature() const {
    return temperature;
}

// Setter function for setting the temperature
void WindTempSolar::setTemperature(float temperature) {
    this->temperature = temperature;
}

// Getter function for retrieving the solar radiation
float WindTempSolar::getSolarRadiation() const {
    return solar_radiation;
}

// Setter function for setting the solar radiation
void WindTempSolar::setSolarRadiation(float solar_radiation) {
    this->solar_radiation = solar_radiation;
}

// Retrieve the value of a specific field from the WindTempSolar object
float WindTempSolar::getValue(const std::string& field) const {
    if (field == "wind_speed") {
        return getWindSpeed();
    } else if (field == "temperature") {
        return getTemperature();
    } else if (field == "solar_radiation") {
        return getSolarRadiation();
    }
    return 0.0f;
}

// Comparison operator for less than
bool WindTempSolar::operator<(const WindTempSolar& other) const {
    // Compare based on wind speed
    if (this->wind_speed < other.wind_speed) {
        return true;
    } else if (this->wind_speed == other.wind_speed) {
        // If wind speeds are equal, compare based on temperature
        if (this->temperature < other.temperature) {
            return true;
        } else if (this->temperature == other.temperature) {
            // If temperatures are also equal, compare based on solar radiation
            return this->solar_radiation < other.solar_radiation;
        }
    }
    return false;
}

// Comparison operator for greater than
bool WindTempSolar::operator>(const WindTempSolar& other) const {
    // Compare based on wind speed
    if (this->wind_speed > other.wind_speed) {
        return true;
    } else if (this->wind_speed == other.wind_speed) {
        // If wind speeds are equal, compare based on temperature
        if (this->temperature > other.temperature) {
            return true;
        } else if (this->temperature == other.temperature) {
            // If temperatures are also equal, compare based on solar radiation
            return this->solar_radiation > other.solar_radiation;
        }
    }
    return false;
}
