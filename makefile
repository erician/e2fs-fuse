.PHONY: clean 
default: e2fs

OBJDIR = obj
SRCDIR = src
TESTDIR = test

# Define the tools we are going to use
CC= gcc
LD = gcc
CFLAGS = -g -Wall -Wno-sign-compare
CFLAGS += -I$(SRCDIR)
CFLAGS += -D_FILE_OFFSET_BITS=64
LIBS = -lm -lc -lpthread -lfuse
AR = ar
ARFLAGS = crv

OBJS += $(OBJDIR)/string_util.o
OBJS += $(OBJDIR)/e2fs_util.o
OBJS += $(SRCDIR)/eastlake.c
OBJS += $(OBJDIR)/e2fs.o

e2fs: $(OBJS)
	$(LD) $(CFLAGS) $^ -o $@ $(LIBS)

# include
include src/makefile
include test/makefile
include test/test-framework/makefile

run-ut: all-ut

clean:
	rm -rf $(OBJDIR)/*

