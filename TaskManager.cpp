#include "TaskManager.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>

TaskManager::TaskManager(const std::string& filename)
    : filename(filename), nextId(1) {
    loadFromFile();
}

TaskManager::~TaskManager() {
    saveToFile();
}

void TaskManager::loadFromFile() {
    std::ifstream file(filename);
    if (!file.is_open()) {
        return; // File doesn't exist yet, that's okay
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;
        try {
            Task task = Task::fromFileFormat(line);
            tasks.push_back(std::make_unique<Task>(task));
            if (task.getId() >= nextId) {
                nextId = task.getId() + 1;
            }
        } catch (const std::exception& e) {
            std::cerr << "Error loading task: " << e.what() << std::endl;
        }
    }
    file.close();
}

void TaskManager::saveToFile() {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file for writing: " << filename << std::endl;
        return;
    }

    for (const auto& task : tasks) {
        file << task->toFileFormat() << "\n";
    }
    file.close();
}

void TaskManager::addTask(const std::string& title, const std::string& description,
                          Priority priority, time_t dueDate) {
    auto task = std::make_unique<Task>(nextId++, title, description, priority, dueDate);
    tasks.push_back(std::move(task));
    saveToFile();
    std::cout << "Task added successfully with ID: " << (nextId - 1) << std::endl;
}

void TaskManager::deleteTask(int id) {
    auto it = std::remove_if(tasks.begin(), tasks.end(),
                            [id](const std::unique_ptr<Task>& task) {
                                return task->getId() == id;
                            });
    
    if (it != tasks.end()) {
        tasks.erase(it, tasks.end());
        saveToFile();
        std::cout << "Task deleted successfully." << std::endl;
    } else {
        std::cout << "Task with ID " << id << " not found." << std::endl;
    }
}

void TaskManager::updateTaskStatus(int id, Status status) {
    Task* task = getTask(id);
    if (task) {
        task->setStatus(status);
        saveToFile();
        std::cout << "Task status updated successfully." << std::endl;
    } else {
        std::cout << "Task with ID " << id << " not found." << std::endl;
    }
}

void TaskManager::updateTaskPriority(int id, Priority priority) {
    Task* task = getTask(id);
    if (task) {
        task->setPriority(priority);
        saveToFile();
        std::cout << "Task priority updated successfully." << std::endl;
    } else {
        std::cout << "Task with ID " << id << " not found." << std::endl;
    }
}

Task* TaskManager::getTask(int id) {
    for (auto& task : tasks) {
        if (task->getId() == id) {
            return task.get();
        }
    }
    return nullptr;
}

std::vector<Task*> TaskManager::getAllTasks() {
    std::vector<Task*> result;
    for (auto& task : tasks) {
        result.push_back(task.get());
    }
    return result;
}

std::vector<Task*> TaskManager::getTasksByStatus(Status status) {
    std::vector<Task*> result;
    for (auto& task : tasks) {
        if (task->getStatus() == status) {
            result.push_back(task.get());
        }
    }
    return result;
}

std::vector<Task*> TaskManager::getTasksByPriority(Priority priority) {
    std::vector<Task*> result;
    for (auto& task : tasks) {
        if (task->getPriority() == priority) {
            result.push_back(task.get());
        }
    }
    return result;
}

std::vector<Task*> TaskManager::searchTasks(const std::string& keyword) {
    std::vector<Task*> result;
    for (auto& task : tasks) {
        if (task->getTitle().find(keyword) != std::string::npos ||
            task->getDescription().find(keyword) != std::string::npos) {
            result.push_back(task.get());
        }
    }
    return result;
}

void TaskManager::displayAllTasks() const {
    if (tasks.empty()) {
        std::cout << "No tasks available." << std::endl;
        return;
    }

    std::cout << "\n" << std::string(80, '=') << std::endl;
    std::cout << "ALL TASKS" << std::endl;
    std::cout << std::string(80, '=') << std::endl;

    for (const auto& task : tasks) {
        std::cout << task->toString() << std::endl;
        std::cout << std::string(80, '-') << std::endl;
    }
}

void TaskManager::displayTasksByStatus(Status status) const {
    std::vector<const Task*> filtered;
    for (const auto& task : tasks) {
        if (task->getStatus() == status) {
            filtered.push_back(task.get());
        }
    }

    if (filtered.empty()) {
        std::cout << "No tasks with status: " << Task::statusToString(status) << std::endl;
        return;
    }

    std::cout << "\n" << std::string(80, '=') << std::endl;
    std::cout << "TASKS - " << Task::statusToString(status) << std::endl;
    std::cout << std::string(80, '=') << std::endl;

    for (const auto& task : filtered) {
        std::cout << task->toString() << std::endl;
        std::cout << std::string(80, '-') << std::endl;
    }
}

void TaskManager::displayTask(int id) const {
    for (const auto& task : tasks) {
        if (task->getId() == id) {
            std::cout << "\n" << task->toString() << std::endl;
            return;
        }
    }
    std::cout << "Task with ID " << id << " not found." << std::endl;
}

int TaskManager::getTaskCount() const {
    return tasks.size();
}

int TaskManager::getCompletedTaskCount() const {
    return std::count_if(tasks.begin(), tasks.end(),
                        [](const std::unique_ptr<Task>& task) {
                            return task->getStatus() == Status::COMPLETED;
                        });
}

int TaskManager::getPendingTaskCount() const {
    return std::count_if(tasks.begin(), tasks.end(),
                        [](const std::unique_ptr<Task>& task) {
                            return task->getStatus() == Status::PENDING;
                        });
}
