//Programa que imprime su pid y espera a una señal para escribir en un archivo ya creado. 
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    printf("[main.c]: %d\n", getpid());
    pause();
    
    return 0;
}

