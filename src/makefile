SHELL = cmd
HDIR = headers
CDIR = implementations
CC = gcc
CFLAGS = -I $(HDIR) -I $(CDIR)

ODIR=obj

_DEPS = boolean.h charmachine.h listdinpos.h listpos.h matrix.h point.h queue.h stack.h wordmachine.h
DEPS = $(patsubst %,$(HDIR)/%,$(_DEPS))

_OBJ = charmachine.o listdinpos.o listpos.o matrix.o point.o queue.o stack.o wordmachine.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: $(CDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/main.o: main.c main.h $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(ODIR)/main.o $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	del $(ODIR)\*.o