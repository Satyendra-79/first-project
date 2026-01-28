#include "Config.h"
#include <iostream>
#include <sstream>
#include <algorithm>

Config::Config(const std::string& filename) : configFile(filename) {
    loadDefaults();
    load();
}

void Config::loadDefaults() {
    // Default configuration values
    settings["data_file"] = "tasks.dat";
    settings["log_file"] = "task_manager.log";
    settings["log_level"] = "INFO";
    settings["auto_save"] = "true";
    settings["backup_enabled"] = "true";
    settings["backup_count"] = "5";
    settings["date_format"] = "%Y-%m-%d %H:%M";
    settings["theme"] = "default";
    settings["page_size"] = "10";
}

bool Config::load() {
    std::ifstream file(configFile);
    if (!file.is_open()) {
        // Config file doesn't exist, create it with defaults
        return save();
    }

    std::string line;
    while (std::getline(file, line)) {
        parseConfigLine(line);
    }
    file.close();
    return true;
}

void Config::parseConfigLine(const std::string& line) {
    // Skip empty lines and comments
    if (line.empty() || line[0] == '#' || line[0] == ';') {
        return;
    }

    size_t pos = line.find('=');
    if (pos != std::string::npos) {
        std::string key = line.substr(0, pos);
        std::string value = line.substr(pos + 1);

        // Trim whitespace
        key.erase(0, key.find_first_not_of(" \t"));
        key.erase(key.find_last_not_of(" \t") + 1);
        value.erase(0, value.find_first_not_of(" \t"));
        value.erase(value.find_last_not_of(" \t") + 1);

        if (!key.empty()) {
            settings[key] = value;
        }
    }
}

bool Config::save() {
    std::ofstream file(configFile);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open config file for writing: " << configFile << std::endl;
        return false;
    }

    file << "# Task Manager Configuration File\n";
    file << "# Generated automatically\n\n";

    for (const auto& pair : settings) {
        file << pair.first << " = " << pair.second << "\n";
    }

    file.close();
    return true;
}

std::string Config::get(const std::string& key, const std::string& defaultValue) const {
    auto it = settings.find(key);
    if (it != settings.end()) {
        return it->second;
    }
    return defaultValue;
}

void Config::set(const std::string& key, const std::string& value) {
    settings[key] = value;
}

int Config::getInt(const std::string& key, int defaultValue) const {
    std::string value = get(key);
    if (value.empty()) {
        return defaultValue;
    }
    try {
        return std::stoi(value);
    } catch (const std::exception&) {
        return defaultValue;
    }
}

bool Config::getBool(const std::string& key, bool defaultValue) const {
    std::string value = get(key);
    if (value.empty()) {
        return defaultValue;
    }
    std::transform(value.begin(), value.end(), value.begin(), ::tolower);
    return value == "true" || value == "1" || value == "yes" || value == "on";
}

bool Config::has(const std::string& key) const {
    return settings.find(key) != settings.end();
}

void Config::display() const {
    std::cout << "\n=== Configuration Settings ===\n";
    for (const auto& pair : settings) {
        std::cout << pair.first << " = " << pair.second << "\n";
    }
    std::cout << "==============================\n";
}
