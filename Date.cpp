#include "Date.h"
#include <sstream>

// Constructors
// Default constructor initializes date to January 1, 0 AD
Date::Date() : day(0), month(0), year(0) {}

// Parameterized constructor initializes date with specified values
Date::Date(int day, int month, int year) : day(day), month(month), year(year) {}

// Constructor parses a date string in the format "dd/mm/yyyy" and initializes the date
Date::Date(const std::string& date_str) {
    std::istringstream ss(date_str); // Create a string stream to parse the date string
    char delimiter;
    ss >> day >> delimiter >> month >> delimiter >> year; // Extract day, month, and year using delimiter '/'
}

// Getters and setters
// Getter for day
int Date::getDay() const {
    return day;
}

// Setter for day
void Date::setDay(int day) {
    this->day = day;
}

// Getter for month
int Date::getMonth() const {
    return month;
}

// Setter for month
void Date::setMonth(int month) {
    this->month = month;
}

// Getter for year
int Date::getYear() const {
    return year;
}

// Setter for year
void Date::setYear(int year) {
    this->year = year;
}

// Comparison operators
// Less than operator
bool Date::operator<(const Date& other) const {
    if (year < other.year)
        return true;
    else if (year == other.year && month < other.month)
        return true;
    else if (year == other.year && month == other.month && day < other.day)
        return true;
    return false;
}

// Greater than operator
bool Date::operator>(const Date& other) const {
    if (year > other.year)
        return true;
    else if (year == other.year && month > other.month)
        return true;
    else if (year == other.year && month == other.month && day > other.day)
        return true;
    return false;
}

// Equal to operator
bool Date::operator==(const Date& other) const {
    return (day == other.day && month == other.month && year == other.year);
}

// Convert date to string
std::string Date::toString() const {
    return std::to_string(day) + "/" + std::to_string(month) + "/" + std::to_string(year);
}

// Overload output operator <<
// Output stream operator to print a Date object
std::ostream& operator<<(std::ostream& os, const Date& date) {
    os << date.toString();
    return os;
}
