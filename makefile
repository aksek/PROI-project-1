
CC = g++
CFLAGS = -std=c++11 -g -Wall -I include
TARGET = bin/runner
DEPS = include/SetOfInts.h
OBJ = build/main.o build/SetOfInts.o

$(TARGET) : $(OBJ) bin
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)
	
build/%.o : src/%.cpp $(DEPS) build
	$(CC) $(CFLAGS) -c -o $@ $<
	
build : 
	mkdir build

bin :
	mkdir bin
	
clean:
	rm -r build
	rm -r bin
	rm include/*.gch
	
.PHONY: clean
