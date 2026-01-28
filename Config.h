#ifndef CONFIG_H
#define CONFIG_H

#include <string>
#include <map>
#include <fstream>

/**
 * @brief Configuration manager for application settings
 */
class Config {
private:
    std::map<std::string, std::string> settings;
    std::string configFile;

    void loadDefaults();
    void parseConfigLine(const std::string& line);

public:
    Config(const std::string& filename = "config.ini");

    /**
     * @brief Load configuration from file
     */
    bool load();

    /**
     * @brief Save configuration to file
     */
    bool save();

    /**
     * @brief Get a configuration value
     */
    std::string get(const std::string& key, const std::string& defaultValue = "") const;

    /**
     * @brief Set a configuration value
     */
    void set(const std::string& key, const std::string& value);

    /**
     * @brief Get integer value
     */
    int getInt(const std::string& key, int defaultValue = 0) const;

    /**
     * @brief Get boolean value
     */
    bool getBool(const std::string& key, bool defaultValue = false) const;

    /**
     * @brief Check if key exists
     */
    bool has(const std::string& key) const;

    /**
     * @brief Display all settings
     */
    void display() const;
};

#endif // CONFIG_H
