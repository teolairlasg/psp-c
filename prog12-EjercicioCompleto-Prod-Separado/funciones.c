//para incluir un fichero local (del proyecto), 
//se pone entre comillas, en lugar de < >
#include "./funciones.h"

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

//para ir bien, esta función devolverá un entero cada vez.
unsigned int int_aleatorio(unsigned int min, unsigned int max){
    
    if(min > max){
        fprintf(stderr, "[int_aleatorio] Warning: se pasó un min mayor que un max, se invierten los valores");
        unsigned int temp = min;
        min = max;
        max = temp;
    }
    unsigned int semilla = (unsigned int) time(NULL);
    srand(semilla);
    unsigned int num_aleatorio = rand();
    //rango define el número total de posibles 
    //candidatos
    unsigned int rango = max-min+1;

    return min+(num_aleatorio%rango);
}

