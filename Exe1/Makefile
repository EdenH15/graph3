CXX = g++
CXXFLAGS = -Wall -std=c++11

TARGET = main
TEST_TARGET = test

SRCS = main.cpp Graph.cpp Algorithms.cpp structures.cpp
TEST_SRCS = AlgoTest.cpp Graph.cpp Algorithms.cpp structures.cpp

OBJS = $(SRCS:.cpp=.o)
TEST_OBJS = $(TEST_SRCS:.cpp=.o)

# Default target to build everything (both main and test)
all: $(TARGET) $(TEST_TARGET)

# Target to build the main program
Main: $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

# Target to build the test program
test: $(TEST_OBJS)
	$(CXX) $(TEST_OBJS) -o $(TEST_TARGET)
	./$(TEST_TARGET)  # Run the test program after building

# Compile .cpp files into .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up generated files
clean:
	rm -f $(OBJS) $(TEST_OBJS) $(TARGET) $(TEST_TARGET)

.PHONY: all clean Main test
