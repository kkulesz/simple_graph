CPPFLAGS := -Wall -g -Iinclude -Isrc

INCLUDE := include
SRC := src
BIN := bin
BUILD := build
MKDIR_P := mkdir -p
TEST:= test

$(BIN)/program: $(BUILD) $(BIN)  $(BUILD)/vertex.o $(BUILD)/graph.o $(BUILD)/main.o
	g++ $(BUILD)/main.o -o $(BIN)/program

$(BUILD)/main.o: $(SRC)/main.cpp $(BUILD)/interface.o
	g++ $(CPPFLAGS) -c $(SRC)/main.cpp -o $(BUILD)/main.o

$(BUILD)/interface.o: $(SRC)/interface.tcc $(INCLUDE)/interface.h $(BUILD)/graph.o
	g++ $(CPPFLAGS) -c $(INCLUDE)/interface.h -o $(BUILD)/interface.o

$(BUILD)/graph.o: $(BUILD)/vertex.o $(SRC)/graph.tcc $(SRC)/bfs.tcc $(INCLUDE)/graph.h
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
