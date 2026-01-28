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

std::vector<Task*> TaskManager::getTasksByCategory(const std::string& category) {
    std::vector<Task*> result;
    for (auto& task : tasks) {
        if (task->getCategory() == category) {
            result.push_back(task.get());
        }
    }
    return result;
}

std::vector<Task*> TaskManager::getTasksByTag(const std::string& tag) {
    std::vector<Task*> result;
    for (auto& task : tasks) {
        if (task->hasTag(tag)) {
            result.push_back(task.get());
        }
    }
    return result;
}

void TaskManager::sortTasksByPriority(std::vector<Task*>& taskList, bool descending) {
    std::sort(taskList.begin(), taskList.end(), 
        [descending](Task* a, Task* b) {
            return descending ? 
                static_cast<int>(a->getPriority()) > static_cast<int>(b->getPriority()) :
                static_cast<int>(a->getPriority()) < static_cast<int>(b->getPriority());
        });
}

void TaskManager::sortTasksByDueDate(std::vector<Task*>& taskList, bool ascending) {
    std::sort(taskList.begin(), taskList.end(),
        [ascending](Task* a, Task* b) {
            return ascending ? a->getDueDate() < b->getDueDate() : a->getDueDate() > b->getDueDate();
        });
}

void TaskManager::sortTasksByTitle(std::vector<Task*>& taskList, bool ascending) {
    std::sort(taskList.begin(), taskList.end(),
        [ascending](Task* a, Task* b) {
            return ascending ? a->getTitle() < b->getTitle() : a->getTitle() > b->getTitle();
        });
}

std::vector<Task*> TaskManager::getOverdueTasks() {
    std::vector<Task*> result;
    time_t now = time(nullptr);
    
    for (auto& task : tasks) {
        if (task->getStatus() != Status::COMPLETED && task->getDueDate() < now) {
            result.push_back(task.get());
        }
    }
    return result;
}

std::vector<Task*> TaskManager::getUpcomingTasks(int days) {
    std::vector<Task*> result;
    time_t now = time(nullptr);
    time_t future = now + (days * 24 * 60 * 60);
    
    for (auto& task : tasks) {
        if (task->getStatus() != Status::COMPLETED && 
            task->getDueDate() >= now && 
            task->getDueDate() <= future) {
            result.push_back(task.get());
        }
    }
    return result;
}

bool TaskManager::exportToJSON(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        return false;
    }

    file << "{\n  \"tasks\": [\n";
    
    for (size_t i = 0; i < tasks.size(); ++i) {
        const auto& task = tasks[i];
        file << "    {\n";
        file << "      \"id\": " << task->getId() << ",\n";
        file << "      \"title\": \"" << task->getTitle() << "\",\n";
        file << "      \"description\": \"" << task->getDescription() << "\",\n";
        file << "      \"category\": \"" << task->getCategory() << "\",\n";
        file << "      \"priority\": \"" << Task::priorityToString(task->getPriority()) << "\",\n";
        file << "      \"status\": \"" << Task::statusToString(task->getStatus()) << "\",\n";
        file << "      \"created_at\": " << task->getCreatedAt() << ",\n";
        file << "      \"due_date\": " << task->getDueDate() << ",\n";
        file << "      \"tags\": [";
        
        auto tags = task->getTags();
        bool firstTag = true;
        for (const auto& tag : tags) {
            if (!firstTag) file << ", ";
            file << "\"" << tag << "\"";
            firstTag = false;
        }
        file << "]\n";
        file << "    }";
        if (i < tasks.size() - 1) file << ",";
        file << "\n";
    }
    
    file << "  ]\n}\n";
    file.close();
    return true;
}

bool TaskManager::exportToCSV(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        return false;
    }

    // CSV Header
    file << "ID,Title,Description,Category,Priority,Status,Created At,Due Date,Tags\n";
    
    for (const auto& task : tasks) {
        file << task->getId() << ","
             << "\"" << task->getTitle() << "\","
             << "\"" << task->getDescription() << "\","
             << "\"" << task->getCategory() << "\","
             << Task::priorityToString(task->getPriority()) << ","
             << Task::statusToString(task->getStatus()) << ","
             << task->getCreatedAt() << ","
             << task->getDueDate() << ",\"";
        
        auto tags = task->getTags();
        bool first = true;
        for (const auto& tag : tags) {
            if (!first) file << ";";
            file << tag;
            first = false;
        }
        file << "\"\n";
    }
    
    file.close();
    return true;
}

bool TaskManager::importFromJSON(const std::string& filename) {
    // Basic JSON import - would need a proper JSON parser for production
    std::cout << "JSON import feature coming soon! Please use the native .dat format for now.\n";
    return false;
}

