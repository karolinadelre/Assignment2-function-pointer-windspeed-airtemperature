#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <sstream>

/**
 * @brief Class to represent a date.
 *
 * This class provides functionality to represent and manipulate dates.
 */
class Date {
public:
    /**
     * @brief Default constructor.
     *
     * Initializes the date to January 1, 0 AD.
     */
    Date();

    /**
     * @brief Constructor with day, month, and year.
     *
     * @param day The day of the month.
     * @param month The month.
     * @param year The year.
     */
    Date(int day, int month, int year);

    /**
     * @brief Constructor from string representation.
     *
     * Parses a date string in the format "DD/MM/YYYY" and initializes the date.
     *
     * @param date_str The string representation of the date.
     */
    Date(const std::string& date_str);

    /**
     * @brief Accessor for the day component of the date.
     *
     * @return The day of the month.
     */
    int getDay() const;

    /**
     * @brief Accessor for the month component of the date.
     *
     * @return The month.
     */
    int getMonth() const;

    /**
     * @brief Accessor for the year component of the date.
     *
     * @return The year.
     */
    int getYear() const;

    /**
     * @brief Mutator for the day component of the date.
     *
     * @param day The day of the month.
     */
    void setDay(int day);

    /**
     * @brief Mutator for the month component of the date.
     *
     * @param month The month.
     */
    void setMonth(int month);

    /**
     * @brief Mutator for the year component of the date.
     *
     * @param year The year.
     */
    void setYear(int year);

    /**
     * @brief Comparison operator less than.
     *
     * @param other The date to compare against.
     * @return true if this date is less than the other date, false otherwise.
     */
    bool operator<(const Date& other) const;

    /**
     * @brief Comparison operator greater than.
     *
     * @param other The date to compare against.
     * @return true if this date is greater than the other date, false otherwise.
     */
    bool operator>(const Date& other) const;

    /**
     * @brief Comparison operator equal to.
     *
     * @param other The date to compare against.
     * @return true if this date is equal to the other date, false otherwise.
     */
    bool operator==(const Date& other) const;

    /**
     * @brief Convert date to string.
     *
     * @return The string representation of the date in the format "DD/MM/YYYY".
     */
    std::string toString() const;

private:
    // Private data members
    int day;    /**< The day of the month. */
    int month;  /**< The month. */
    int year;   /**< The year. */
};

// Overload output operator <<
/**
 * @brief Overload output stream operator for printing a Date object.
 *
 * @param os The output stream.
 * @param date The Date object to be printed.
 * @return The output stream.
 */
std::ostream& operator<<(std::ostream& os, const Date& date);

#endif // DATE_H

