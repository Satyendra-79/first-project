#include "Validator.h"
#include <algorithm>
#include <cctype>
#include <regex>

bool Validator::isNotEmpty(const std::string& str) {
    return !trim(str).empty();
}

bool Validator::isValidLength(const std::string& str, size_t minLen, size_t maxLen) {
    size_t len = trim(str).length();
    return len >= minLen && len <= maxLen;
}

bool Validator::isAlphanumeric(const std::string& str) {
    if (str.empty()) return false;
    
    return std::all_of(str.begin(), str.end(), [](char c) {
        return std::isalnum(c) || std::isspace(c) || 
               c == '.' || c == ',' || c == '-' || c == '_' ||
               c == '!' || c == '?' || c == ':' || c == ';';
    });
}

bool Validator::isInRange(int value, int min, int max) {
    return value >= min && value <= max;
}

bool Validator::isValidDays(int days) {
    return days >= 0 && days <= 365; // Max 1 year in the future
}

std::string Validator::sanitize(const std::string& str) {
    std::string result = trim(str);
    
    // Remove dangerous characters that might cause issues
    result.erase(std::remove_if(result.begin(), result.end(), 
        [](char c) { return c == '|' || c == '\n' || c == '\r'; }), 
        result.end());
    
    return result;
}

std::string Validator::trim(const std::string& str) {
    size_t first = str.find_first_not_of(" \t\n\r");
    if (first == std::string::npos) return "";
    
    size_t last = str.find_last_not_of(" \t\n\r");
    return str.substr(first, (last - first + 1));
}

bool Validator::isValidTaskId(int id) {
    return id > 0 && id < 1000000; // Reasonable upper limit
}

bool Validator::isValidEmail(const std::string& email) {
    // Simple email validation using regex
    const std::regex pattern(
        R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)"
    );
    return std::regex_match(email, pattern);
}
