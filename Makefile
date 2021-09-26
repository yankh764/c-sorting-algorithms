CC = gcc
CFLAGS = -march=native -O2 -pipe -fstack-protector-strong -Wextra \
		 -Wall -Wundef -Wformat=2 -I$(INCLUDE)

DST_DIR = /usr/local/bin

BIN ?= mdoc
INCLUDE ?= include/
OBJDIR ?= build
SRCDIR ?= src

.PHONY: test

test: 
	$(CC) $(CFLAGS) src/* test.c
