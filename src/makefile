SHELL = cmd
HDIR = headers
CDIR = implementations
CC = gcc
CFLAGS = -I $(HDIR) -I $(CDIR)

ODIR = obj
BDIR = bin

_DEPS = boolean.h charmachine.h listdinpos.h matrix.h point.h wordmachine.h \
        list_todo.h node_todo.h q_pesanan.h \
        gadget.h inventoryGadget.h listpos.h \
        inprogress.h node_order.h prioqueue.h tas.h \
        item.h ability.h time.h
DEPS = $(patsubst %,$(HDIR)/%,$(_DEPS))

_OBJ = item.o ability.o time.o \
       listdinpos.o matrix.o point.o \
       charmachine.o wordmachine.o config.o\
       list_todo.o node_todo.o q_pesanan.o \
       gadget.o inventoryGadget.o listpos.o \
       inprogress.o node_order.o prioqueue.o tas.o \
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: $(CDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/main.o: main.c main.h $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(ODIR)/main.o $(OBJ)
	$(CC) -o $(BDIR)/$@ $^ $(CFLAGS)

.PHONY: clean

clean:
	del $(ODIR)\*.o