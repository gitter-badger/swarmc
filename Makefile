CSRC    = $(shell find -type f -name '*.c')
INCD    = $(subst .,-I.,$(dir $(shell find -type f -name "*.h"))) $(subst .,-I.,$(dir $(shell find -type f -name "*.h")))..
LIBS    = -llua5.1 -lcrypto

CC     ?= gcc
CFLAGS ?= -O2 -g -fdiagnostics-color=auto -I./src/include -march=native -mtune=native

all:
	$(CC) $(CFLAGS) $(CSRC) $(INCD) $(LIBS) -o swarmc
	@chmod 0755 ./swarmc

all_ugly_tabs:
	$(CC) $(CFLAGS) $(CSRC) $(INCD) $(LIBS) -D__UGLY_TABS__ -o swarmc
	@chmod 0755 ./swarmc
