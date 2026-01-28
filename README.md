# Task Management System 📝

A **professional, enterprise-grade** command-line Task Management System built in C++ that demonstrates advanced Object-Oriented Programming principles, modern C++ features, and software engineering best practices.

[![C++ CI/CD](https://github.com/Satyendra-79/first-project/workflows/C++%20CI/CD%20Pipeline/badge.svg)](https://github.com/Satyendra-79/first-project/actions)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![C++ Standard](https://img.shields.io/badge/C++-14-blue.svg)](https://isocpp.org/)

## ✨ Professional Features

### Core Functionality

- **Task Creation & Management**: Add, update, delete, and modify tasks with ease
- **Priority Levels**: Organize tasks by LOW, MEDIUM, or HIGH priority
- **Status Tracking**: Track tasks through PENDING, IN_PROGRESS, and COMPLETED states
- **Due Date Management**: Set and track task deadlines
- **Data Persistence**: Automatically saves and loads tasks from file

### Advanced Features ⚡

- **Tags System**: Add multiple tags to tasks for flexible organization
- **Categories**: Group tasks by custom categories (Work, Personal, etc.)
- **Advanced Search**: Search tasks by keywords, tags, or categories
- **Smart Filtering**: Filter by status, priority, tags, overdue, or upcoming
- **Multi-level Sorting**: Sort by priority, due date, or title
- **Statistics Dashboard**: Comprehensive analytics and insights
- **Export/Import**: Export to JSON or CSV formats for backup and analysis

### Professional Architecture 🏗️

- **Logging System**: Multi-level logging (DEBUG, INFO, WARNING, ERROR, CRITICAL)
- **Configuration Management**: Customizable settings via config.ini
- **Input Validation**: Robust validation for data integrity
- **Error Handling**: Comprehensive error handling throughout
- **Unit Testing**: Custom test framework with extensive test coverage
- **CI/CD Pipeline**: Automated testing with GitHub Actions
- **Modern C++ Practices**: Smart pointers, STL containers, RAII principles

## 🛠️ Technologies Used

- **Language**: C++14
- **Core Concepts**:
  - Object-Oriented Programming (Classes, Encapsulation, Abstraction)
  - Design Patterns (Singleton, Factory patterns)
  - Smart Pointers (std::unique_ptr, std::make_unique)
  - STL Containers (std::vector, std::set, std::map)
  - File I/O (std::fstream)
  - Enumerations and Type Safety
  - Lambda Functions and Modern C++ Features
  - Template Programming
  - Error Handling with Exceptions

### Project Components

- **Task**: Core task entity with tags and categories
- **TaskManager**: Manages task collection with advanced filtering
- **Logger**: Singleton logging system for debugging
- **Config**: Configuration management system
- **Validator**: Input validation utilities
- **TestFramework**: Custom unit testing framework

## � Installation & Usage

### Prerequisites

- C++ compiler with C++14 support (g++ 5.0+, clang++ 3.4+, or MSVC 2015+)
- GNU Make
- Git (for cloning)

### Quick Start

#### 1. Clone the Repository

```bash
git clone https://github.com/Satyendra-79/first-project.git
cd first-project
```

#### 2. Build the Project

```bash
make          # Build the application
make test     # Build and run tests
```

#### 3. Run the Application

```bash
./task_manager
```

#### One-Command Build & Run

```bash
make run
```

## 📖 How to Use

### Main Menu Options

1. **Add New Task** - Create tasks with title, description, priority, due date, category, and tags
2. **View All Tasks** - Display all tasks with complete details
3. **View Tasks by Status** - Filter by PENDING, IN_PROGRESS, or COMPLETED
4. **Update Task Status** - Change task status
5. **Update Task Priority** - Modify priority levels
6. **Delete Task** - Remove tasks by ID
7. **Search Tasks** - Search by keywords, tags, or categories
8. **View Statistics** - See analytics and insights
9. **Advanced Options** - Sorting, filtering, export/import
10. **Exit** - Save and exit

### Example Workflow

```
1. Add New Task
   → Enter: "Complete project documentation"
   → Category: "Work"
   → Add tags: "urgent", "documentation"

2. View Tasks by Status → See all pending tasks

3. Update Task Status → Mark as IN_PROGRESS

4. Export to JSON → Backup your tasks

5. View Statistics → Track your productivity
```

## 📁 Project Structure

```
first-project/
├── .github/
│   └── workflows/
│       └── ci.yml              # GitHub Actions CI/CD
├── Task.h / Task.cpp           # Task entity with tags & categories
├── TaskManager.h / TaskManager.cpp  # Task management with filtering
├── Logger.h / Logger.cpp       # Logging system
├── Config.h / Config.cpp       # Configuration management
├── Validator.h / Validator.cpp # Input validation
├── TestFramework.h             # Unit testing framework
├── main.cpp                    # CLI application entry point
├── tests.cpp                   # Unit tests
├── Makefile                    # Build configuration
├── index.html                  # Project website
├── config.ini                  # Configuration file (auto-generated)
├── tasks.dat                   # Task data file (auto-generated)
├── task_manager.log            # Application logs (auto-generated)
├── README.md                   # This file
├── CHANGELOG.md                # Version history
├── CONTRIBUTING.md             # Contribution guidelines
├── LICENSE                     # MIT License
└── .editorconfig               # Editor configuration
```

## 🔧 Makefile Commands

```bash
make          # Build the project
make test     # Build and run unit tests
make run      # Build and run the application
make clean    # Remove build files
make cleanall # Remove build and data files
make format   # Format code with clang-format
make analyze  # Run static code analysis (cppcheck)
make install  # Install to system (requires sudo)
make uninstall# Uninstall from system
make help     # Show all available commands
```

## 💡 Key Features Highlights

### For Developers & Resume

This project demonstrates:

1. **Modern C++ Expertise**:
   - C++14 features, smart pointers, STL mastery
   - Design patterns (Singleton, Factory)
   - Template programming and type safety

2. **Software Architecture**:
   - Clean code principles and SOLID design
   - Separation of concerns and modularity
   - Professional error handling and logging

3. **Professional Development**:
   - Unit testing with custom framework
   - CI/CD pipeline with GitHub Actions
   - Code quality tools (cppcheck, clang-format)
   - Comprehensive documentation

4. **Real-World Features**:
   - Data persistence and file I/O
   - Configuration management
   - Input validation and security
   - Export/import functionality
   - Advanced filtering and sorting

5. **Best Practices**:
   - Version control with Git
   - Automated testing
   - Code documentation
   - Contributing guidelines
   - Changelog maintenance

## 🧪 Testing

Run the comprehensive test suite:

```bash
make test
```

The project includes unit tests for:

- Task creation and management
- Tag and category functionality
- Input validation
- Data serialization
- Sorting and filtering

## 🔍 Code Quality

The project maintains high code quality through:

- **Static Analysis**: `make analyze` runs cppcheck
- **Code Formatting**: `make format` ensures consistent style
- **Continuous Integration**: Automated builds on multiple platforms
- **Unit Tests**: Comprehensive test coverage

## 📊 Configuration

Edit `config.ini` to customize:

```ini
data_file = tasks.dat
log_file = task_manager.log
log_level = INFO
auto_save = true
backup_enabled = true
backup_count = 5
date_format = %Y-%m-%d %H:%M
theme = default
page_size = 10
```

## 🚀 Advanced Usage

### Export Tasks

```bash
# The application menu provides export options
# Export to JSON: Full task data in JSON format
# Export to CSV: Spreadsheet-compatible format
```

### Search & Filter

```bash
# Search by keyword across all fields
# Filter by tags, categories, status
# View overdue or upcoming tasks
# Sort by priority, date, or title
```

## 🤝 Contributing

Contributions are welcome! Please read [CONTRIBUTING.md](CONTRIBUTING.md) for guidelines.

1. Fork the repository
2. Create your feature branch
3. Add tests for new features
4. Ensure all tests pass
5. Submit a pull request

## 📝 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 🌟 Acknowledgments

- Built with modern C++ best practices
- Inspired by professional task management systems
- Designed for learning and demonstration purposes

## 📧 Contact

- **Author**: Satyendra
- **GitHub**: [@Satyendra-79](https://github.com/Satyendra-79)
- **Project**: [first-project](https://github.com/Satyendra-79/first-project)

## 🎯 Future Enhancements

Potential features for future versions:

- [ ] Web API with REST endpoints
- [ ] Database integration (SQLite)
- [ ] Multi-user support
- [ ] Task collaboration features
- [ ] Mobile companion app
- [ ] Notification system
- [ ] Task templates
- [ ] Recurring tasks
- [ ] Time tracking
- [ ] Report generation

---

⭐ **If you find this project helpful, please consider giving it a star!**

Made with ❤️ and C++

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
