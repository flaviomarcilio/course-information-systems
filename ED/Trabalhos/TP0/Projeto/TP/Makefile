#---------------------------------------------------------------------
# Arquivo	: Makefile
# Conteúdo	: compilar o programa matop
# Autor		: Wagner Meira Jr. (meira@dcc.ufmg.br)
# Histórico	: 2021-10-18 - arquivo criado
#		: 2021-10-21 - estrutura de diretórios
#---------------------------------------------------------------------
# Opções	: make all - compila tudo
#		: make clean - remove objetos e executável
#---------------------------------------------------------------------

CC = gcc
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/matop.o $(OBJ)/mat.o $(OBJ)/memlog.o
HDRS = $(INC)/mat.h $(INC)/memlog.h $(INC)/msgassert.h
CFLAGS = -Wall -c -I$(INC)

EXE = $(BIN)/matop

all: $(EXE)
	$(EXE) -s -p /tmp/somalog.out -l -x 4 -y 5
	$(EXE) -m -p /tmp/multlog.out -l -x 5 -y 5
	$(EXE) -t -p /tmp/transplog.out -l -x 5 -y 4

test: $(EXE)
	$(EXE) -s -p somalog100.out -o soma100.out -x 100 -y 100
	$(EXE) -s -p somalog200.out -o soma200.out -x 200 -y 200
	$(EXE) -s -p somalog300.out -o soma300.out -x 300 -y 300
	$(EXE) -s -p somalog400.out -o soma400.out -x 400 -y 400
	$(EXE) -s -p somalog500.out -o soma500.out -x 500 -y 500
	$(EXE) -m -p multlog100.out -o mult100.out -x 100 -y 100
	$(EXE) -m -p multlog200.out -o mult200.out -x 200 -y 200
	$(EXE) -m -p multlog300.out -o mult300.out -x 300 -y 300
	$(EXE) -m -p multlog400.out -o mult400.out -x 400 -y 400
	$(EXE) -m -p multlog500.out -o mult500.out -x 500 -y 500
	$(EXE) -t -p tranlog100.out -o tran100.out -x 100 -y 100
	$(EXE) -t -p tranlog200.out -o tran200.out -x 200 -y 200
	$(EXE) -t -p tranlog300.out -o tran300.out -x 300 -y 300
	$(EXE) -t -p tranlog400.out -o tran400.out -x 400 -y 400
	$(EXE) -t -p tranlog500.out -o tran500.out -x 500 -y 500
	$(EXE) -s -p somaMemLog.out -o somaMem.out -x 5 -y 5 -l
	$(EXE) -m -p multMemLog.out -o multMem.out -x 5 -y 5 -l
	$(EXE) -t -p tranMemLog.out -o tranMem.out -x 5 -y 5 -l

$(BIN)/matop: $(OBJS)
	$(CC) -o $(BIN)/matop $(OBJS) $(LIBS)

$(OBJ)/matop.o: $(HDRS) $(SRC)/matop.c
	$(CC) $(CFLAGS) -o $(OBJ)/matop.o $(SRC)/matop.c

$(OBJ)/mat.o: $(HDRS) $(SRC)/mat.c
	$(CC) $(CFLAGS) -o $(OBJ)/mat.o $(SRC)/mat.c

$(OBJ)/memlog.o: $(HDRS) $(SRC)/memlog.c
	$(CC) $(CFLAGS) -o $(OBJ)/memlog.o $(SRC)/memlog.c
	
clean:
	rm -rf $(EXE) $(OBJS) 
