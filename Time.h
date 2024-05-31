#ifndef TIME_H
#define TIME_H

#include <string>

/**
 * @brief Class to represent a time.
 *
 * This class provides functionality to represent and manipulate times.
 */
class Time {
public:
    /**
     * @brief Default constructor.
     *
     * Initializes the time to 00:00.
     */
    Time();

    /**
     * @brief Constructor with hour and minute.
     *
     * @param hour The hour.
     * @param minute The minute.
     */
    Time(int hour, int minute);

    /**
     * @brief Constructor from string representation.
     *
     * Parses a time string in the format "HH:MM" and initializes the time.
     *
     * @param time_str The string representation of the time.
     */
    Time(const std::string& time_str);

    /**
     * @brief Accessor for the hour component of the time.
     *
     * @return The hour.
     */
    int getHour() const;

    /**
     * @brief Mutator for the hour component of the time.
     *
     * @param hour The hour.
     */
    void setHour(int hour);

    /**
     * @brief Accessor for the minute component of the time.
     *
     * @return The minute.
     */
    int getMinute() const;

    /**
     * @brief Mutator for the minute component of the time.
     *
     * @param minute The minute.
     */
    void setMinute(int minute);

    /**
     * @brief Convert time to string.
     *
     * @return The string representation of the time in the format "HH:MM".
     */
    std::string toString() const;

private:
    // Private data members
    int hour;   /**< The hour. */
    int minute; /**< The minute. */
};

#endif
