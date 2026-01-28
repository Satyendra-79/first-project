# Changelog

All notable changes to this project will be documented in this file.

## [2.0.0] - 2026-01-28

### Added

- **Logging System**: Professional logging with multiple levels (DEBUG, INFO, WARNING, ERROR, CRITICAL)
- **Configuration Management**: Flexible configuration system with config.ini file support
- **Input Validation**: Robust validator class for data integrity
- **Tags System**: Add multiple tags to tasks for better organization
- **Categories**: Organize tasks by categories
- **Advanced Filtering**:
  - Filter by tags
  - Filter by categories
  - View overdue tasks
  - View upcoming tasks
- **Sorting Options**:
  - Sort by priority (ascending/descending)
  - Sort by due date (ascending/descending)
  - Sort by title (alphabetical)
- **Export/Import**:
  - Export tasks to JSON format
  - Export tasks to CSV format
  - Import from JSON (in development)
- **Unit Testing Framework**: Custom test framework with comprehensive tests
- **CI/CD Pipeline**: GitHub Actions workflow for automated testing
- **Modern HTML UI**: Professional responsive web interface

### Enhanced

- Improved error handling throughout the application
- Better file format with backward compatibility
- Enhanced statistics dashboard
- Professional code documentation

### Technical Improvements

- Refactored codebase with better separation of concerns
- Added smart pointers and modern C++ practices
- Implemented Singleton pattern for Logger
- Enhanced code quality with static analysis support

## [1.0.0] - Initial Release

### Added

- Basic task creation and management
- Priority levels (LOW, MEDIUM, HIGH)
- Status tracking (PENDING, IN_PROGRESS, COMPLETED)
- File persistence
- Search functionality
- Statistics dashboard
- Command-line interface
