# Makefile for compiling plot.cpp

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11

# Include directories
INCLUDES = -I/usr/include/python3.12 \
           -I/home/batman/.local/lib/python3.12/site-packages/numpy/_core/include

# Libraries to link against
LIBS = -lpython3.12

# Source file
SRC_BUBBLE = bubble_sort.cpp
SRC_INSERTION = insertion_sort.cpp
SRC_SELECTION = selection_sort.cpp
SRC_QUICK = quick_sort.cpp

# Output executable
# TARGET = bubble_sort 

# Default target
all: $(TARGET)

# Targets for different implementations
bubble_sort: $(SRC_BUBBLE)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(LIBS) $(SRC_BUBBLE) -o bubble && ./bubble

insertion_sort: $(SRC_INSERTION)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(LIBS) $(SRC_INSERTION) -o insertion && ./insertion

selection_sort: $(SRC_SELECTION)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(LIBS) $(SRC_SELECTION) -o selection && ./selection

quick_sort: $(SRC_QUICK)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(LIBS) $(SRC_QUICK) -o quick && ./quick

# Compile the source file into the target executable
# $(TARGET): $(SRC)
# 	$(CXX) $(CXXFLAGS) $(INCLUDES) $(LIBS) -o $(TARGET) $(SRC)

# Clean up the build
clean:
	rm -f $(TARGET)

