CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g -Iinclude

SRC = src/*.cpp
TARGET = main

all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

run: all
	./$(TARGET)