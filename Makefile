CC=gcc
CFLAGS=-I. -pthread
DEPS = libbamboo.h
OBJ = main.o 
LDIR =./lib

# The builds from travis need lib math (-lm) and lib dynamic library (-ldl)
LIBS = -lbamboo_core -ldl -lm

%.o: %.c $(DEPS)
	$(CC) -c -g0 -Os -o $@ $< $(CFLAGS) 

main: $(OBJ)
	$(CC) -g0 -Os -o $@ $^ $(CFLAGS) -L $(LDIR) $(LIBS) $(CFLAGS)

clean:
	rm -rf *.o main
