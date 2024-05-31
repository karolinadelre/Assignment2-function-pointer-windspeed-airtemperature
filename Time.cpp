#include "Time.h"
#include <sstream>

// Default constructor initializes time to 00:00
Time::Time() : hour(0), minute(0) {}

// Parameterized constructor initializes time with specified values
Time::Time(int hour, int minute) : hour(hour), minute(minute) {}

// Constructor parses a time string in the format "hh:mm" and initializes the time
Time::Time(const std::string& time_str) {
    std::istringstream ss(time_str); // Create a string stream to parse the time string
    char delimiter;
    ss >> hour >> delimiter >> minute; // Extract hour and minute using delimiter ':'
}

// Getter for hour
int Time::getHour() const {
    return hour;
}

// Setter for hour
void Time::setHour(int hour) {
    this->hour = hour;
}

// Getter for minute
int Time::getMinute() const {
    return minute;
}

// Setter for minute
void Time::setMinute(int minute) {
    this->minute = minute;
}

// Returns a string representation of the time in the format "hh:mm"
std::string Time::toString() const {
    // Format hour and minute to ensure two digits (e.g., 02 instead of 2)
    std::string hour_str = (hour < 10) ? "0" + std::to_string(hour) : std::to_string(hour);
    std::string minute_str = (minute < 10) ? "0" + std::to_string(minute) : std::to_string(minute);
    return hour_str + ":" + minute_str; // Concatenate hour and minute with ':'
}

