SHELL = cmd
CC = gcc

ODIR = obj
BDIR = bin
DDIR = drivers

MODDIR = Modules
BASICDIR = Basic
BASIC = $(patsubst %,$(MODDIR)/%,$(BASICDIR))
CONFIGDIR = Configurations
CONFIG = $(patsubst %,$(MODDIR)/%,$(CONFIGDIR))
GADGETDIR = Gadget_Inventory
GADGET = $(patsubst %,$(MODDIR)/%,$(GADGETDIR))
MAINDIR = Main
MAIN = $(patsubst %,$(MODDIR)/%,$(MAINDIR))
MAPLOCDIR = Map_Locations
MAPLOC = $(patsubst %,$(MODDIR)/%,$(MAPLOCDIR))
PESANDIR = Pesanan
PESAN = $(patsubst %,$(MODDIR)/%,$(PESANDIR))
TODODIR = Todo_Inprogress
TODO = $(patsubst %,$(MODDIR)/%,$(TODODIR))

CFLAGS = -I $(BASIC) -I $(CONFIG) -I $(GADGET) -I $(MAIN) -I $(MAPLOC) -I $(PESAN) -I $(TODO)

_OBJ = item.o ability.o time.o color.o\
       listdinpos.o matrix.o point.o \
       charmachine.o wordmachine.o config.o\
       gadget.o inventoryGadget.o listpos.o \
       list_todo.o node_todo.o tas.o \
       q_pesanan.o \
       main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

_DRIVE = item.o ability.o time.o color.o\
       listdinpos.o matrix.o point.o \
       charmachine.o wordmachine.o config.o\
       gadget.o inventoryGadget.o listpos.o \
       list_todo.o node_todo.o tas.o \
       q_pesanan.o
DRIVE = $(patsubst %,$(ODIR)/%,$(_DRIVE))

$(ODIR)/%.o: $(BASIC)/%.c
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/%.o: $(CONFIG)/%.c
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/%.o: $(GADGET)/%.c
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/%.o: $(MAIN)/%.c
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/%.o: $(MAPLOC)/%.c
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/%.o: $(PESAN)/%.c
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/%.o: $(TODO)/%.c
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $(BDIR)/$@ $^

dconfig: $(DDIR)/dconfig.c $(DRIVE)
	$(CC) -o $(BDIR)/$(DDIR)/$@ $^ $(CFLAGS)

dgadinv: $(DDIR)/dgadinv.c $(DRIVE)
	$(CC) -o $(BDIR)/$(DDIR)/$@ $^ $(CFLAGS)

dmaploc: $(DDIR)/dmaploc.c $(DRIVE)
	$(CC) -o $(BDIR)/$(DDIR)/$@ $^ $(CFLAGS)

dpesanan: $(DDIR)/dpesanan.c $(DRIVE)
	$(CC) -o $(BDIR)/$(DDIR)/$@ $^ $(CFLAGS)

dability: $(DDIR)/dability.c $(DRIVE)
	$(CC) -o $(BDIR)/$(DDIR)/$@ $^ $(CFLAGS)

ditem: $(DDIR)/ditem.c $(DRIVE)
	$(CC) -o $(BDIR)/$(DDIR)/$@ $^ $(CFLAGS)
	
dtas: $(DDIR)/dtas.c $(DRIVE)
	$(CC) -o $(BDIR)/$(DDIR)/$@ $^ $(CFLAGS)

dtodoinpro: $(DDIR)/dtodoinpro.c $(DRIVE)
	$(CC) -o $(BDIR)/$(DDIR)/$@ $^ $(CFLAGS)

.PHONY: clean

clean:
	del $(ODIR)\*.o