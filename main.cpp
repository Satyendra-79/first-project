#include "TaskManager.h"
#include <iostream>
#include <limits>
#include <ctime>

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void displayMenu() {
    std::cout << "\n";
    std::cout << "╔════════════════════════════════════════════╗\n";
    std::cout << "║     TASK MANAGEMENT SYSTEM - MENU          ║\n";
    std::cout << "╚════════════════════════════════════════════╝\n";
    std::cout << "  1. Add New Task\n";
    std::cout << "  2. View All Tasks\n";
    std::cout << "  3. View Tasks by Status\n";
    std::cout << "  4. Update Task Status\n";
    std::cout << "  5. Update Task Priority\n";
    std::cout << "  6. Delete Task\n";
    std::cout << "  7. Search Tasks\n";
    std::cout << "  8. View Statistics\n";
    std::cout << "  9. Exit\n";
    std::cout << "════════════════════════════════════════════\n";
    std::cout << "Enter your choice: ";
}

void waitForEnter() {
    std::cout << "\nPress Enter to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

Priority getPriorityFromUser() {
    int choice;
    std::cout << "\nSelect Priority:\n";
    std::cout << "1. LOW\n";
    std::cout << "2. MEDIUM\n";
    std::cout << "3. HIGH\n";
    std::cout << "Choice: ";
    std::cin >> choice;

    switch (choice) {
        case 1: return Priority::LOW;
        case 2: return Priority::MEDIUM;
        case 3: return Priority::HIGH;
        default: return Priority::MEDIUM;
    }
}

Status getStatusFromUser() {
    int choice;
    std::cout << "\nSelect Status:\n";
    std::cout << "1. PENDING\n";
    std::cout << "2. IN_PROGRESS\n";
    std::cout << "3. COMPLETED\n";
    std::cout << "Choice: ";
    std::cin >> choice;

    switch (choice) {
        case 1: return Status::PENDING;
        case 2: return Status::IN_PROGRESS;
        case 3: return Status::COMPLETED;
        default: return Status::PENDING;
    }
}

time_t getDueDateFromUser() {
    int days;
    std::cout << "Days until due date: ";
    std::cin >> days;
    
    time_t now = time(nullptr);
    return now + (days * 24 * 60 * 60); // Convert days to seconds
}

void addTaskMenu(TaskManager& manager) {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    std::string title, description;
    std::cout << "\n=== Add New Task ===\n";
    std::cout << "Title: ";
    std::getline(std::cin, title);
    
    std::cout << "Description: ";
    std::getline(std::cin, description);
    
    Priority priority = getPriorityFromUser();
    time_t dueDate = getDueDateFromUser();
    
    manager.addTask(title, description, priority, dueDate);
}

void viewTasksByStatusMenu(TaskManager& manager) {
    Status status = getStatusFromUser();
    manager.displayTasksByStatus(status);
}

void updateTaskStatusMenu(TaskManager& manager) {
    int id;
    std::cout << "\nEnter Task ID: ";
    std::cin >> id;
    
    Status status = getStatusFromUser();
    manager.updateTaskStatus(id, status);
}

void updateTaskPriorityMenu(TaskManager& manager) {
    int id;
    std::cout << "\nEnter Task ID: ";
    std::cin >> id;
    
    Priority priority = getPriorityFromUser();
    manager.updateTaskPriority(id, priority);
}

void deleteTaskMenu(TaskManager& manager) {
    int id;
    std::cout << "\nEnter Task ID to delete: ";
    std::cin >> id;
    
    char confirm;
    std::cout << "Are you sure? (y/n): ";
    std::cin >> confirm;
    
    if (confirm == 'y' || confirm == 'Y') {
        manager.deleteTask(id);
    } else {
        std::cout << "Deletion cancelled." << std::endl;
    }
}

void searchTasksMenu(TaskManager& manager) {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    std::string keyword;
    std::cout << "\nEnter search keyword: ";
    std::getline(std::cin, keyword);
    
    auto results = manager.searchTasks(keyword);
    
    if (results.empty()) {
        std::cout << "No tasks found matching '" << keyword << "'" << std::endl;
    } else {
        std::cout << "\n=== Search Results ===\n";
        for (const auto& task : results) {
            std::cout << task->toString() << std::endl;
            std::cout << std::string(80, '-') << std::endl;
        }
    }
}

void viewStatisticsMenu(TaskManager& manager) {
    std::cout << "\n╔════════════════════════════════════════════╗\n";
    std::cout << "║           TASK STATISTICS                  ║\n";
    std::cout << "╚════════════════════════════════════════════╝\n";
    std::cout << "  Total Tasks:     " << manager.getTaskCount() << "\n";
    std::cout << "  Pending:         " << manager.getPendingTaskCount() << "\n";
    std::cout << "  Completed:       " << manager.getCompletedTaskCount() << "\n";
    std::cout << "  In Progress:     " << (manager.getTaskCount() - 
                                            manager.getPendingTaskCount() - 
                                            manager.getCompletedTaskCount()) << "\n";
    std::cout << "════════════════════════════════════════════\n";
}

int main() {
    TaskManager manager("tasks.dat");
    int choice;
    bool running = true;

    std::cout << "╔════════════════════════════════════════════╗\n";
    std::cout << "║  Welcome to Task Management System!        ║\n";
    std::cout << "║  Organize your tasks efficiently           ║\n";
    std::cout << "╚════════════════════════════════════════════╝\n";

    while (running) {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                addTaskMenu(manager);
                waitForEnter();
                break;
            case 2:
                manager.displayAllTasks();
                waitForEnter();
                break;
            case 3:
                viewTasksByStatusMenu(manager);
                waitForEnter();
                break;
            case 4:
                updateTaskStatusMenu(manager);
                waitForEnter();
                break;
            case 5:
                updateTaskPriorityMenu(manager);
                waitForEnter();
                break;
            case 6:
                deleteTaskMenu(manager);
                waitForEnter();
                break;
            case 7:
                searchTasksMenu(manager);
                waitForEnter();
                break;
            case 8:
                viewStatisticsMenu(manager);
                waitForEnter();
                break;
            case 9:
                std::cout << "\nThank you for using Task Management System!\n";
                running = false;
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                waitForEnter();
        }
    }

    return 0;
}
