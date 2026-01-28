# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++14 -Wall -Wextra -O2

# Target executable name
TARGET = task_manager
TEST_TARGET = test_runner

# Source files
SRCS = main.cpp Task.cpp TaskManager.cpp Logger.cpp Config.cpp Validator.cpp

# Test source files
TEST_SRCS = tests.cpp Task.cpp TaskManager.cpp Logger.cpp Config.cpp Validator.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)
TEST_OBJS = $(TEST_SRCS:.cpp=.o)

# Header files (for dependencies)
HEADERS = Task.h TaskManager.h Logger.h Config.h Validator.h TestFramework.h

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): $(OBJS)
	@echo "Linking $(TARGET)..."
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)
	@echo "✓ Build complete! Run with: ./$(TARGET)"

# Build tests
$(TEST_TARGET): $(TEST_OBJS)
	@echo "Linking $(TEST_TARGET)..."
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) $(TEST_OBJS)
	@echo "✓ Test build complete!"

# Compile source files to object files
%.o: %.cpp $(HEADERS)
	@echo "Compiling $<..."
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Build and run tests
test: $(TEST_TARGET)
	@echo ""
	@echo "Running tests..."
	./$(TEST_TARGET)

# Clean build files
clean:
	@echo "Cleaning build files..."
	rm -f $(OBJS) $(TEST_OBJS) $(TARGET) $(TEST_TARGET)
	@echo "✓ Clean complete!"

# Clean everything including data files
cleanall: clean
	rm -f tasks.dat config.ini task_manager.log *.json *.csv
	@echo "✓ All files cleaned!"

# Run the program
run: $(TARGET)
	./$(TARGET)

# Format code (requires clang-format)
format:
	@echo "Formatting code..."
	find . -name '*.cpp' -o -name '*.h' | xargs clang-format -i
	@echo "✓ Code formatted!"

# Static analysis (requires cppcheck)
analyze:
	@echo "Running static analysis..."
	cppcheck --enable=all --suppress=missingIncludeSystem *.cpp *.h
	@echo "✓ Analysis complete!"

# Install (optional - copies to /usr/local/bin)
install: $(TARGET)
	@echo "Installing $(TARGET) to /usr/local/bin..."
	sudo cp $(TARGET) /usr/local/bin/
	@echo "✓ Installation complete!"

# Uninstall
uninstall:
	@echo "Uninstalling $(TARGET)..."
	sudo rm -f /usr/local/bin/$(TARGET)
	@echo "✓ Uninstall complete!"

# Help target
help:
	@echo "Available targets:"
	@echo "  make          - Build the project"
	@echo "  make test     - Build and run unit tests"
	@echo "  make run      - Build and run the application"
	@echo "  make clean    - Remove build files"
	@echo "  make cleanall - Remove all generated files"
	@echo "  make format   - Format code with clang-format"
	@echo "  make analyze  - Run static code analysis"
	@echo "  make install  - Install to system (requires sudo)"
	@echo "  make uninstall- Uninstall from system"
	@echo "  make help     - Show this help message"

.PHONY: all clean cleanall run test format analyze install uninstall help

