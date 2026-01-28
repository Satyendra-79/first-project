#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include "Task.h"
#include <vector>
#include <string>
#include <memory>

/**
 * @brief TaskManager class to manage multiple tasks
 */
class TaskManager {
private:
    std::vector<std::unique_ptr<Task>> tasks;
    int nextId;
    std::string filename;

    void loadFromFile();
    void saveToFile();

public:
    /**
     * @brief Constructor for TaskManager
     * @param filename The file to store tasks
     */
    TaskManager(const std::string& filename = "tasks.dat");

    /**
     * @brief Destructor - saves tasks before exit
     */
    ~TaskManager();

    // Task operations
    void addTask(const std::string& title, const std::string& description, 
                 Priority priority, time_t dueDate);
    void deleteTask(int id);
    void updateTaskStatus(int id, Status status);
    void updateTaskPriority(int id, Priority priority);
    Task* getTask(int id);

    // Query operations
    std::vector<Task*> getAllTasks();
    std::vector<Task*> getTasksByStatus(Status status);
    std::vector<Task*> getTasksByPriority(Priority priority);
    std::vector<Task*> searchTasks(const std::string& keyword);

    // Display operations
    void displayAllTasks() const;
    void displayTasksByStatus(Status status) const;
    void displayTask(int id) const;

    // Statistics
    int getTaskCount() const;
    int getCompletedTaskCount() const;
    int getPendingTaskCount() const;
};

#endif // TASKMANAGER_H
