#Este es un fichero para la compilación automática.
#Para compilar ambos programas,
# simplemente usa el comando "make" desde dentro
# del directorio.

PADRE    = padre-consumidor.exe
CC       = gcc
PRODUTOR = productor.exe

CFLAGS   = -Wall

OBJ_PADRE = funciones.o main.o
OBJ_PRODUCTOR = funciones.o productor.o

all: $(PADRE) $(PRODUTOR)

$(PADRE): $(OBJ_PADRE)
	$(CC) -o $@ $^

$(PRODUTOR): $(OBJ_PRODUCTOR)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@rm -rf *.o $(PADRE) $(PRODUTOR)
