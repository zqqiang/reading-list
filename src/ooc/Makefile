IDIR =../include
CC=gcc
#CFLAGS=-I$(IDIR)
CFLAGS=-I./

ODIR=obj
LDIR =../lib

LIBS=-lm

_DEPS = new.h set.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = new.o set.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

#$(ODIR)/%.o: %.c $(DEPS)
$(ODIR)/%.o: %.c %.h
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/main.o: main.c
	$(CC) -c -o $@ $< $(CFLAGS)

all: $(OBJ) $(ODIR)/main.o
	gcc -o ooc $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 