SHELL = /bin/bash
CC = gcc-9
CFLAGS = -g -pthread
SRC = $(wildcard *.c)
EXE = $(patsubst %.c, %, $(SRC))

all: ${EXE}

%:      %.c
	${CC} ${CFLAGS} $@.c -o $@ 

clean:
	rm ${EXE}
