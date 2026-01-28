#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <string>
#include <vector>

/**
 * @brief Input validation utilities
 */
class Validator {
public:
    /**
     * @brief Validate that string is not empty
     */
    static bool isNotEmpty(const std::string& str);

    /**
     * @brief Validate string length
     */
    static bool isValidLength(const std::string& str, size_t minLen, size_t maxLen);

    /**
     * @brief Validate that string contains only alphanumeric and spaces
     */
    static bool isAlphanumeric(const std::string& str);

    /**
     * @brief Validate integer input in range
     */
    static bool isInRange(int value, int min, int max);

    /**
     * @brief Validate date (number of days)
     */
    static bool isValidDays(int days);

    /**
     * @brief Sanitize string input (trim whitespace, remove special chars)
     */
    static std::string sanitize(const std::string& str);

    /**
     * @brief Trim whitespace from both ends
     */
    static std::string trim(const std::string& str);

    /**
     * @brief Check if task ID is valid (positive integer)
     */
    static bool isValidTaskId(int id);

    /**
     * @brief Validate email format (for future features)
     */
    static bool isValidEmail(const std::string& email);
};

#endif // VALIDATOR_H
