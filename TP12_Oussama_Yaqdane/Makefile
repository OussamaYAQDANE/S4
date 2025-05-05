CXX = g++
CXXFLAGS = -std=c++17 -Wall

SOURCES = $(wildcard exo*.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLES = $(SOURCES:.cpp=)

all: $(EXECUTABLES)

%: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	rm -f $(EXECUTABLES) $(OBJECTS)

run: $(EXECUTABLES)
	for exe in $(EXECUTABLES); do \
		./$$exe; \
	done
