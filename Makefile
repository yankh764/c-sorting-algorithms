CC = gcc
CFLAGS = -march=native -O2 -pipe -fstack-protector-strong -Wextra \
		 -Wall -Wundef -Wformat=2 -Wstrict-overflow=5 -I$(INCLUDE)

DST_DIR = /usr/local/bin

BIN ?= mdoc
INCLUDE ?= include/
OBJDIR ?= build
SRCDIR ?= src

.PHONY: test

test: 
	gcc $(CFLAGS) src/* test.c
