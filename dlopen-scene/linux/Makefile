CC = gcc

CFLAGS= -shared -fPIC

all:dvbtest yang

dvbtest:./libdvbtest/dvbtest.c
	${CC} $< -o ./lib/libdvbtest.so ${CFLAGS}

yang:yang.c
	${CC} $< -o $@ -ldl

clean:
	rm -rf yang ./lib/*.so
