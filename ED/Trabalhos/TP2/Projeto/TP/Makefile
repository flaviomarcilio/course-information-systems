CC = g++
BIN = bin
INC = include
OBJ = obj
SRC = src

OBJS = $(OBJ)/item.o $(OBJ)/heap.o $(OBJ)/ordenacao.o $(OBJ)/ordenacao_externa.o $(OBJ)/main.o $(OBJ)/memlog.o
HDRS = $(INC)/item.h $(INC)/heap.h $(INC)/ordenacao.h $(INC)/ordenacao_externa.h $(INC)/memlog.h
CFLAGS = -Wall -c -I $(INC)

all: $(BIN)/main

$(BIN)/main: $(OBJS)
	$(CC) $(OBJS) -o $(BIN)/main

$(OBJ)/item.o: $(HDRS) $(SRC)/item.cpp
	$(CC) $(CFLAGS) $(SRC)/item.cpp -o $(OBJ)/item.o

$(OBJ)/heap.o: $(HDRS) $(SRC)/heap.cpp
	$(CC) $(CFLAGS) $(SRC)/heap.cpp -o $(OBJ)/heap.o

$(OBJ)/ordenacao.o: $(HDRS) $(SRC)/ordenacao.cpp
	$(CC) $(CFLAGS) $(SRC)/ordenacao.cpp -o $(OBJ)/ordenacao.o

$(OBJ)/ordenacao_externa.o: $(HDRS) $(SRC)/ordenacao_externa.cpp
	$(CC) $(CFLAGS) $(SRC)/ordenacao_externa.cpp -o $(OBJ)/ordenacao_externa.o

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) $(SRC)/main.cpp -o $(OBJ)/main.o

$(OBJ)/memlog.o: $(HDRS) $(SRC)/memlog.cpp
	$(CC) $(CFLAGS) $(SRC)/memlog.cpp -o $(OBJ)/memlog.o

clean:
	rm $(OBJ)/* $(BIN)/*