# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall

# Find all the exo{n}.cpp files in the directory
SOURCES = $(wildcard exo*.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLES = $(SOURCES:.cpp=)

# Default rule to compile everything
all: $(EXECUTABLES)

# Rule to compile each exo{n}.cpp into an executable
%: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

# Clean up the compiled files
clean:
	rm -f $(EXECUTABLES) $(OBJECTS)

# Run all executables
run: $(EXECUTABLES)
	for exe in $(EXECUTABLES); do \
		./$$exe; \
	done
