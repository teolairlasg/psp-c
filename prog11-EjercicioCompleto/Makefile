#Este es un fichero para la compilación automática.
#Para compilar, simplemente usa el comando "make"
#desde dentro del directorio.

EXEC     = programa.exe
CC       = gcc

CFLAGS   = -Wall

SRC      = $(wildcard *.c)
OBJ      = $(SRC:.c=.o)

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@rm -rf *.o $(EXEC)
