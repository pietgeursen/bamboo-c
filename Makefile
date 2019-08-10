CC=gcc
CFLAGS=-I.
DEPS = libbamboo.h
OBJ = main.o 
LDIR =./lib

LIBS = -lbamboo_core

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) 

main: $(OBJ)
	$(CC) -Oz -o $@ $^ $(CFLAGS) -L $(LDIR) $(LIBS)

clean:
	rm -rf *.o main
