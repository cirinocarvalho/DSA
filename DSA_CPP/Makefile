# Makefile for DSA_CPP project
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g
TARGET = dsa_cpp
SRCDIR = .
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

# Default target
all: $(TARGET)

# Link the executable
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)
	@echo "Build complete! Run with: ./$(TARGET)"

# Compile source files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -f $(OBJECTS) $(TARGET)
	@echo "Clean complete!"

# Run the program
run: $(TARGET)
	./$(TARGET)

# Install dependencies (if needed)
install:
	@echo "No external dependencies required for this project"

# Help target
help:
	@echo "Available targets:"
	@echo "  all     - Build the project"
	@echo "  clean   - Remove build files"
	@echo "  run     - Build and run the project"
	@echo "  help    - Show this help message"

.PHONY: all clean run install help