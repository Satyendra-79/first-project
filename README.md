# Task Management System 📝

A professional command-line Task Management System built in C++ that demonstrates Object-Oriented Programming principles, file I/O operations, and efficient data management.

## 🌟 Features

- **Task Creation**: Add tasks with title, description, priority levels, and due dates
- **Task Management**: Update, delete, and modify tasks easily
- **Priority Levels**: Organize tasks by LOW, MEDIUM, or HIGH priority
- **Status Tracking**: Track tasks through PENDING, IN_PROGRESS, and COMPLETED states
- **Search Functionality**: Search tasks by keywords in title or description
- **Data Persistence**: Automatically saves and loads tasks from file
- **Statistics Dashboard**: View task completion statistics and analytics
- **User-Friendly CLI**: Intuitive menu-driven interface

## 🛠️ Technologies Used

- **Language**: C++14
- **Concepts**: 
  - Object-Oriented Programming (Classes, Encapsulation)
  - Smart Pointers (std::unique_ptr, std::make_unique)
  - STL Containers (std::vector)
  - File I/O (std::fstream)
  - Enumerations
  - Lambda Functions

## 📋 Prerequisites

- C++ compiler with C++14 support (g++, clang++)
- GNU Make (for building with Makefile)
- Linux/Unix or Windows (with MinGW) or macOS

## 🚀 Installation & Usage

### Clone or Download
```bash
git clone https://github.com/Satyendra-79/first-project.git
cd first-project
```

### Build the Project
```bash
make
```

### Run the Application
```bash
./task_manager
```

Or build and run in one command:
```bash
make run
```

## 📖 How to Use

1. **Start the application** - Run `./task_manager`
2. **Main Menu Options**:
   - `1` - Add a new task
   - `2` - View all tasks
   - `3` - View tasks by status (Pending/In Progress/Completed)
   - `4` - Update task status
   - `5` - Update task priority
   - `6` - Delete a task
   - `7` - Search for tasks
   - `8` - View statistics
   - `9` - Exit

3. **Example Workflow**:
   ```
   1. Add New Task → Enter details
   2. View All Tasks → See your task list
   3. Update Task Status → Mark tasks as in-progress or completed
   4. View Statistics → Track your progress
   ```

## 📁 Project Structure

```
first-project/
├── Task.h              # Task class header
├── Task.cpp            # Task class implementation
├── TaskManager.h       # TaskManager class header
├── TaskManager.cpp     # TaskManager class implementation
├── main.cpp            # Main program with CLI
├── Makefile            # Build configuration
├── README.md           # Project documentation
└── tasks.dat           # Data file (created automatically)
```

## 🔧 Makefile Commands

```bash
make          # Build the project
make clean    # Remove build files
make cleanall # Remove build and data files
make run      # Build and run
make install  # Install to system (requires sudo)
make help     # Show all commands
```

## 💡 Key Features for Resume

This project demonstrates:

1. **OOP Design**: Well-structured classes with clear separation of concerns
2. **Memory Management**: Use of smart pointers for automatic memory management
3. **Data Persistence**: File I/O for saving and loading data
4. **Error Handling**: Robust exception handling
5. **Modern C++ Practices**: C++14 features including lambda functions, smart pointers
6. **Clean Code**: Well-documented, maintainable code with clear naming conventions
7. **Build System**: Professional Makefile with multiple targets

## 🎯 Learning Outcomes

- Object-Oriented Programming in C++
- File handling and data persistence
- STL containers and algorithms
- Memory management with smart pointers
- Building modular, maintainable applications
- Command-line interface design

## 📝 Example Usage

```
╔════════════════════════════════════════════╗
║  Welcome to Task Management System!        ║
║  Organize your tasks efficiently           ║
╚════════════════════════════════════════════╝

╔════════════════════════════════════════════╗
║     TASK MANAGEMENT SYSTEM - MENU          ║
╚════════════════════════════════════════════╝
  1. Add New Task
  2. View All Tasks
  3. View Tasks by Status
  ...
```

## 🤝 Contributing

Contributions, issues, and feature requests are welcome!

## 📄 License

This project is open source and available under the [MIT License](LICENSE).

## 👤 Author

**Satyendra**
- GitHub: [@Satyendra-79](https://github.com/Satyendra-79)

## 🌟 Show Your Support

Give a ⭐️ if this project helped you!

---

**Note**: This project was created as a portfolio piece to demonstrate C++ programming skills for resume purposes.

My first new repo.
<br>
Raja here (Ahtasham)
