#ifndef TASK_H
#define TASK_H

#include <string>
#include <ctime>

/**
 * @brief Enumeration for task priority levels
 */
enum class Priority {
    LOW,
    MEDIUM,
    HIGH
};

/**
 * @brief Enumeration for task status
 */
enum class Status {
    PENDING,
    IN_PROGRESS,
    COMPLETED
};

/**
 * @brief Task class representing a single task
 */
class Task {
private:
    int id;
    std::string title;
    std::string description;
    Priority priority;
    Status status;
    time_t createdAt;
    time_t dueDate;

public:
    /**
     * @brief Constructor for Task
     */
    Task(int id, const std::string& title, const std::string& description, 
         Priority priority, time_t dueDate);

    // Getters
    int getId() const;
    std::string getTitle() const;
    std::string getDescription() const;
    Priority getPriority() const;
    Status getStatus() const;
    time_t getCreatedAt() const;
    time_t getDueDate() const;

    // Setters
    void setTitle(const std::string& title);
    void setDescription(const std::string& description);
    void setPriority(Priority priority);
    void setStatus(Status status);
    void setDueDate(time_t dueDate);

    // Utility methods
    std::string toString() const;
    std::string toFileFormat() const;
    static Task fromFileFormat(const std::string& line);
    static std::string priorityToString(Priority p);
    static std::string statusToString(Status s);
    static Priority stringToPriority(const std::string& str);
    static Status stringToStatus(const std::string& str);
};

#endif // TASK_H
