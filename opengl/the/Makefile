# OpenGL the

CXX := g++
CXXFLAGS := -Wall -Wextra -Wpedantic -pipe -g -std=c++20
LDFLAGS := -lGL -lglfw -lGLEW

BIN := ./the
SRC := ./src/main.cc
OBJ := ./main.cc.o

all: $(BIN)

$(BIN): $(OBJ)
	$(CXX) $< -o $@ $(LDFLAGS)

$(OBJ): $(SRC)
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean

clean:
	rm $(OBJ) $(BIN)
