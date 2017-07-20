#demo  gcc -fPIC -shared hello.c -o libhello.so
DIR_INC = ./include
DIR_SRC = ./src
DIR_LIB = ./dvbtest
DIR_OBJ = ./obj
DIR_BIN = ./bin
LIB_INSTALL = ./lib

PWD = $(shell pwd)

SRC = $(wildcard ${DIR_SRC}/*.c)  
OBJ = $(patsubst %.c,${DIR_OBJ}/%.o,$(notdir ${SRC})) 

TARGET = yang

BIN_TARGET = ${DIR_BIN}/${TARGET}

CC = gcc
CFLAGS = -g -Wall -I${DIR_INC}

${BIN_TARGET}:${OBJ} ${DIR_LIB}.o
	@echo $(PWD)
	$(CC) $(OBJ)  -o $@ -L ./ $<

${DIR_OBJ}/%.o:${DIR_SRC}/%.c
	$(CC) $(CFLAGS) -c  $< -o $@

${DIR_LIB}.so:$(DIR_LIB)/*.c
	$(CC) -fPIC -shared $< -o $@

.PHONY:clean

clean:
	find ${DIR_OBJ} -name *.o -exec rm -rf {}
