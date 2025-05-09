CXX = g++
SRC = $(wildcard *.cpp)
HDR = $(wildcard *.hpp)
HAHA = $(SRC:.cpp=.haha)
TARGET = main

all: $(TARGET)

%.haha: %.cpp
	$(CXX) -c $< -o $@


$(TARGET): $(HAHA)
	$(CXX) $(HAHA) -o $(TARGET)


clean:
	rm *.haha $(TARGET)
run:
	./$(TARGET)