CSRC    = $(shell find -type f -name '*.c')
INCD    = $(subst .,-I.,$(dir $(shell find -type f -name "*.h"))) $(subst .,-I.,$(dir $(shell find -type f -name "*.h")))..
LIBS    = -llua5.1

CC     ?= gcc
CFLAGS ?= -O2 -g -fdiagnostics-color=auto

all:
	$(CC) $(CFLAGS) $(CSRC) $(INCD) $(LIBS) -o swarm.o
	@chmod 0755 ./swarm.o
