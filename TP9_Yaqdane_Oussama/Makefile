# Makefile for compiling and running C++ project

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -std=c++17

# Executable name
TARGET = main

# Source files
SRCS = main.cpp \
       ./Savings_Account/Savings_Account.cpp \
       ./Account/Account.cpp \
       ./Checking_Account/Checking_Account.cpp \
       ./Trust_Account/Trust_Account.cpp \
       ./Account_Util/Account_Util.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

# Link object files into final executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile .cpp to .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run the program
run: $(TARGET)
	./$(TARGET)

# Clean build files
clean:
	rm -f $(TARGET) $(OBJS)

.PHONY: all clean run
