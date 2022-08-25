CXX = g++
CFLAGS = -c -Wall
LDFLAGS = -lm

BUILD_DIR = build

SOURCES = main.cpp common.cpp square_equation.cpp unittest.cpp
OBJECTS = $(SOURCES:%.cpp=$(BUILD_DIR)/%.o)
EXECUTABLE = solve_equation

.PHONY: all clean 
all: $(BUILD_DIR)/$(EXECUTABLE) 

$(BUILD_DIR)/$(EXECUTABLE): $(OBJECTS) 
	$(CXX) $(LDFLAGS) $^ -o $@

$(BUILD_DIR)/%.o: %.cpp
	$(CXX) -c $< -o $@  

clean:
	rm -rf $(BUILD_DIR)/*

