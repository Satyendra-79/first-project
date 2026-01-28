# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++14 -Wall -Wextra -O2

# Target executable name
TARGET = task_manager

# Source files
SRCS = main.cpp Task.cpp TaskManager.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Header files (for dependencies)
HEADERS = Task.h TaskManager.h

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): $(OBJS)
	@echo "Linking..."
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)
	@echo "Build complete! Run with: ./$(TARGET)"

# Compile source files to object files
%.o: %.cpp $(HEADERS)
	@echo "Compiling $<..."
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	@echo "Cleaning build files..."
	rm -f $(OBJS) $(TARGET)
	@echo "Clean complete!"

# Clean everything including data files
cleanall: clean
	rm -f tasks.dat
	@echo "All files cleaned!"

# Run the program
run: $(TARGET)
	./$(TARGET)

# Install (optional - copies to /usr/local/bin)
install: $(TARGET)
	@echo "Installing $(TARGET) to /usr/local/bin..."
	sudo cp $(TARGET) /usr/local/bin/
	@echo "Installation complete!"

# Uninstall
uninstall:
	@echo "Uninstalling $(TARGET)..."
	sudo rm -f /usr/local/bin/$(TARGET)
	@echo "Uninstallation complete!"

# Help
help:
	@echo "Available targets:"
	@echo "  make          - Build the project"
	@echo "  make clean    - Remove build files"
	@echo "  make cleanall - Remove build and data files"
	@echo "  make run      - Build and run the program"
	@echo "  make install  - Install to system (requires sudo)"
	@echo "  make uninstall- Uninstall from system"
	@echo "  make help     - Show this help message"

.PHONY: all clean cleanall run install uninstall help
