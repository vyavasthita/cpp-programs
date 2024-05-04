# Project directory structure
INC_DIR := include
SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin

EXE := $(BIN_DIR)/practice

CC = g++

OBJECTS = myheader.o \
          main.o

TARGET := practice
all: $(TARGET)
$(TARGET): $(OBJECTS)
	@echo "🚧 Building..."
	g++ -o $(TARGET) $(OBJECTS)
myheader.o: $(SRC_DIR)/myheader.cpp
	g++ -c -I $(INC_DIR) $(SRC_DIR)/myheader.cpp myheader.o
main.o: $(SRC_DIR)/main.cpp
	g++ -c main.o $(SRC_DIR)/main.cpp
.PHONY : clean
clean:
	rm $(OBJECTS)
	rm $(TARGET)