CPPFLAGS := -Wall -g -Iinclude

INCLUDE := include
SRC := src
BIN := bin
BUILD := build
MKDIR_P := mkdir -p
TEST:= test

$(BIN)/program: $(BUILD)/main.o $(BUILD)/vertex.o $(BUILD)/graph.o
	g++ $(BUILD)/vertex.o $(BUILD)/main.o -o $(BIN)/program

$(BUILD)/main.o: $(SRC)/main.cpp $(BUILD)/graph.o
	g++ $(CPPFLAGS) -c $(SRC)/main.cpp -o $(BUILD)/main.o

$(BUILD)/vertex.o: $(SRC)/vertex.cpp $(INCLUDE)/vertex.h
	g++ $(CPPFLAGS) -c $(SRC)/vertex.cpp -o $(BUILD)/vertex.o

$(BUILD)/graph.o: $(SRC)/graph.cpp $(BUILD)/vertex.o $(INCLUDE)/graph.h $(SRC)/graph.cpp
	g++ $(CPPFLAGS) -c $(SRC)/graph.cpp -o $(BUILD)/graph.o

clean:
	rm -f $(BUILD)/*.o
	rm -f $(BIN)/program

