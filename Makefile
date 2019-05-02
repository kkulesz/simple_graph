CPPFLAGS := -Wall -g -Iinclude -Isrc

INCLUDE := include
SRC := src
BIN := bin
BUILD := build
MKDIR_P := mkdir -p
TEST:= test

$(BIN)/program: $(BUILD) $(BIN)  $(BUILD)/vertex.o $(BUILD)/graph.o $(BUILD)/main.o
	g++ $(BUILD)/main.o -o $(BIN)/program

$(BUILD)/main.o: $(SRC)/main.cpp $(BUILD)/graph.o
	g++ $(CPPFLAGS) -c $(SRC)/main.cpp -o $(BUILD)/main.o

$(BUILD)/graph.o: $(BUILD)/vertex.o $(INCLUDE)/graph.h $(SRC)/graph.tcc $(SRC)/bfs.tcc
	g++ $(CPPFLAGS) -c $(INCLUDE)/graph.h -o $(BUILD)/graph.o

$(BUILD)/vertex.o: $(SRC)/vertex.cpp $(INCLUDE)/vertex.h
	g++ $(CPPFLAGS) -c $(SRC)/vertex.cpp -o $(BUILD)/vertex.o


#####
clean:
	rm -f $(BUILD)/*.o
	rm -f $(BIN)/program
	rm -f $(BIN)/test
#####
test: $(BUILD) $(BIN) $(BUILD)/vertex.o $(BUILD)/graph.o $(BUILD)/test.o
	g++ $(BUILD)/test.o -o $(BIN)/test

$(BUILD)/test.o: $(TEST)/test.cpp $(BUILD)/graph.o
	g++ $(CPPFLAGS) -c $(TEST)/test.cpp -o $(BUILD)/test.o
#####
