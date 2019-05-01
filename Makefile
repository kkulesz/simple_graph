CPPFLAGS := -Wall -g -Iinclude

INCLUDE := include
SRC := src
BIN := bin
BUILD := build
MKDIR_P := mkdir -p
TEST:= test

$(BIN)/program: $(BUILD)/main.o $(BUILD)/vertex.o $(BUILD)/graph.o $(BUILD)/bfs.o
	g++ $(BUILD)/main.o -o $(BIN)/program

$(BUILD)/main.o: $(SRC)/main.cpp $(BUILD)/graph.o $(BUILD)/bfs.o
	g++ $(CPPFLAGS) -c $(SRC)/main.cpp -o $(BUILD)/main.o

$(BUILD)/vertex.o: $(SRC)/vertex.cpp $(INCLUDE)/vertex.h
	g++ $(CPPFLAGS) -c $(SRC)/vertex.cpp -o $(BUILD)/vertex.o

$(BUILD)/graph.o: $(SRC)/graph.tcc $(BUILD)/vertex.o $(INCLUDE)/graph.h
	g++ $(CPPFLAGS) -c $(SRC)/graph.tcc -o $(BUILD)/graph.o

$(BUILD)/bfs.o: $(SRC)/bfs.tcc $(BUILD)/vertex.o $(INCLUDE)/graph.h
	g++ $(CPPFLAGS) -c $(SRC)/bfs.tcc -o $(BUILD)/bfs.o

clean:
	rm -f $(BUILD)/*.o
	rm -f $(BIN)/program

