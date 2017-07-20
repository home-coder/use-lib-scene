#demo  gcc -fPIC -shared hello.c -o libhello.so
#或者指定.bashrc中导入本地lib库的路径到环境变量export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:xxxxx/lib
#demo  sudo cp libhello.so /usr/lib/
#demo  gcc main.c -o main -lhello
DIR_INC = ./include
DIR_SRC = ./src
DIR_LIB = ./dvbtest
DIR_OBJ = ./obj
DIR_BIN = ./bin
LIB_INSTALL = ./lib

PWD = $(shell pwd)

#SRC = $(wildcard ${DIR_SRC}/*.c)
#OBJ = $(patsubst %.c,${DIR_OBJ}/%.o,$(notdir ${SRC}))

TARGET = yang

BIN_TARGET = ${DIR_BIN}/${TARGET}

CC = gcc
CFLAGS = -g -Wall -I${DIR_INC}

#${DIR_LIB}/%.so:$(DIR_LIB)/%.c
#	@echo ${DIR_LIB}/%.so:$(DIR_LIB)/%.c
#	$(CC) -fPIC -shared $< -o $@
#
#${BIN_TARGET}:${OBJ} 
#	@echo $(PWD)
#	$(CC) $(OBJ)  -o $@ -L ./ $<
#
#${DIR_OBJ}/%.o:${DIR_SRC}/%.c
#	@echo ${DIR_OBJ}/%.o:${DIR_SRC}/%.c
#	$(CC) $(CFLAGS) -c  $< -o $@

yang:${DIR_SRC}/yang.c libtest
	gcc $< -o ${DIR_BIN}/yang -I ${DIR_INC} -L ${LIB_INSTALL} -ltest

libtest:${DIR_LIB}/test.c
	gcc -fPIC -shared $< -o ${LIB_INSTALL}/libtest.so

.PHONY:clean

clean:
	find ${DIR_OBJ} -name *.o |xargs rm -rf {}
