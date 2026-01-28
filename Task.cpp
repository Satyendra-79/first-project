#include "Task.h"
#include <sstream>
#include <iomanip>
#include <vector>
#include <algorithm>

Task::Task(int id, const std::string& title, const std::string& description,
           Priority priority, time_t dueDate)
    : id(id), title(title), description(description), priority(priority),
      status(Status::PENDING), dueDate(dueDate), category("General") {
    createdAt = time(nullptr);
}

// Getters
int Task::getId() const { return id; }
std::string Task::getTitle() const { return title; }
std::string Task::getDescription() const { return description; }
Priority Task::getPriority() const { return priority; }
Status Task::getStatus() const { return status; }
time_t Task::getCreatedAt() const { return createdAt; }
time_t Task::getDueDate() const { return dueDate; }
std::set<std::string> Task::getTags() const { return tags; }
std::string Task::getCategory() const { return category; }

// Setters
void Task::setTitle(const std::string& title) { this->title = title; }
void Task::setDescription(const std::string& description) { this->description = description; }
void Task::setPriority(Priority priority) { this->priority = priority; }
void Task::setStatus(Status status) { this->status = status; }
void Task::setDueDate(time_t dueDate) { this->dueDate = dueDate; }
void Task::setCategory(const std::string& category) { this->category = category; }

// Tag management
void Task::addTag(const std::string& tag) {
    if (!tag.empty()) {
        tags.insert(tag);
    }
}

void Task::removeTag(const std::string& tag) {
    tags.erase(tag);
}

bool Task::hasTag(const std::string& tag) const {
    return tags.find(tag) != tags.end();
}

void Task::clearTags() {
    tags.clear();
}

// Convert priority enum to string
std::string Task::priorityToString(Priority p) {
    switch (p) {
        case Priority::LOW: return "LOW";
        case Priority::MEDIUM: return "MEDIUM";
        case Priority::HIGH: return "HIGH";
        default: return "UNKNOWN";
    }
}

// Convert status enum to string
std::string Task::statusToString(Status s) {
    switch (s) {
        case Status::PENDING: return "PENDING";
        case Status::IN_PROGRESS: return "IN_PROGRESS";
        case Status::COMPLETED: return "COMPLETED";
        default: return "UNKNOWN";
    }
}

// Convert string to priority enum
Priority Task::stringToPriority(const std::string& str) {
    if (str == "LOW") return Priority::LOW;
    if (str == "MEDIUM") return Priority::MEDIUM;
    if (str == "HIGH") return Priority::HIGH;
    return Priority::MEDIUM; // default
}

// Convert string to status enum
Status Task::stringToStatus(const std::string& str) {
    if (str == "PENDING") return Status::PENDING;
    if (str == "IN_PROGRESS") return Status::IN_PROGRESS;
    if (str == "COMPLETED") return Status::COMPLETED;
    return Status::PENDING; // default
}

// Format time_t to string
std::string formatTime(time_t time) {
    char buffer[80];
    struct tm* timeinfo = localtime(&time);
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M", timeinfo);
    return std::string(buffer);
}

// Display task as string
std::string Task::toString() const {
    std::ostringstream oss;
    oss << "Task ID: " << id << "\n"
        << "Title: " << title << "\n"
        << "Description: " << description << "\n"
        << "Category: " << category << "\n"
        << "Priority: " << priorityToString(priority) << "\n"
        << "Status: " << statusToString(status) << "\n"
        << "Created: " << formatTime(createdAt) << "\n"
        << "Due Date: " << formatTime(dueDate) << "\n";
    
    if (!tags.empty()) {
        oss << "Tags: ";
        bool first = true;
        for (const auto& tag : tags) {
            if (!first) oss << ", ";
            oss << tag;
            first = false;
        }
        oss << "\n";
    }
    
    return oss.str();
}

// Convert task to file format (CSV-like)
std::string Task::toFileFormat() const {
    std::ostringstream oss;
    oss << id << "|" << title << "|" << description << "|"
        << static_cast<int>(priority) << "|"
        << static_cast<int>(status) << "|"
        << createdAt << "|" << dueDate << "|" << category << "|";
    
    // Serialize tags
    bool first = true;
    for (const auto& tag : tags) {
        if (!first) oss << ",";
        oss << tag;
        first = false;
    }
    
    return oss.str();
}

// Parse task from file format
Task Task::fromFileFormat(const std::string& line) {
    std::istringstream iss(line);
    std::string token;
    std::vector<std::string> tokens;

    while (std::getline(iss, token, '|')) {
        tokens.push_back(token);
    }

    if (tokens.size() < 7) {
        throw std::runtime_error("Invalid file format");
    }

    int id = std::stoi(tokens[0]);
    std::string title = tokens[1];
    std::string description = tokens[2];
    Priority priority = static_cast<Priority>(std::stoi(tokens[3]));
    Status status = static_cast<Status>(std::stoi(tokens[4]));
    time_t createdAt = std::stoll(tokens[5]);
    time_t dueDate = std::stoll(tokens[6]);

    Task task(id, title, description, priority, dueDate);
    task.status = status;
    task.createdAt = createdAt;
    
    // Parse category and tags if available
    if (tokens.size() >= 8) {
        task.category = tokens[7];
    }
    
    if (tokens.size() >= 9 && !tokens[8].empty()) {
        std::istringstream tagStream(tokens[8]);
        std::string tag;
        while (std::getline(tagStream, tag, ',')) {
            if (!tag.empty()) {
                task.addTag(tag);
            }
        }
    }

    return task;
}
