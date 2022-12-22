CC = g++
BIN = bin
INC = include
OBJ = obj
SRC = src
TEST = test

OBJS = $(OBJ)/url.o $(OBJ)/lista_encadeada.o $(OBJ)/fila_encadeada.o $(OBJ)/escalonador.o $(OBJ)/main.o $(OBJ)/memlog.o
HDRS = $(INC)/url.h $(INC)/lista_encadeada.h $(INC)/fila_encadeada.h $(INC)/escalonador.h $(INC)/excecao.h $(INC)/memlog.h
CFLAGS = -Wall -c -I $(INC)

all: $(BIN)/main

$(BIN)/main: $(OBJS)
	$(CC) $(OBJS) -o $(BIN)/main

$(OBJ)/url.o: $(HDRS) $(SRC)/url.cpp
	$(CC) $(CFLAGS) $(SRC)/url.cpp -o $(OBJ)/url.o

$(OBJ)/lista_encadeada.o: $(HDRS) $(SRC)/lista_encadeada.cpp
	$(CC) $(CFLAGS) $(SRC)/lista_encadeada.cpp -o $(OBJ)/lista_encadeada.o

$(OBJ)/fila_encadeada.o: $(HDRS) $(SRC)/fila_encadeada.cpp
	$(CC) $(CFLAGS) $(SRC)/fila_encadeada.cpp -o $(OBJ)/fila_encadeada.o

$(OBJ)/escalonador.o: $(HDRS) $(SRC)/escalonador.cpp
	$(CC) $(CFLAGS) $(SRC)/escalonador.cpp -o $(OBJ)/escalonador.o

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) $(SRC)/main.cpp -o $(OBJ)/main.o

$(OBJ)/memlog.o: $(HDRS) $(SRC)/memlog.cpp
	$(CC) $(CFLAGS) $(SRC)/memlog.cpp -o $(OBJ)/memlog.o

clean:
	rm $(OBJ)/*.o
	rm $(BIN)/*