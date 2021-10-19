#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void gestionar_interrupcion(int senyal){
    //imprime un mensaje con el número de señal.
    printf("Recibida la señal número %d\n", senyal);
    //sale del programa sin ejecutar nada más.
    exit(0);
}

int main(int argc, char const *argv[])
{
    //signal vincula una función a una señal
    signal(SIGINT, gestionar_interrupcion);
    printf("hola mundo\n");

    // sleep(30);  //sleep para la ejecución durante 30 segundos.
    //pause para la ejecución hasta que le llegue al proceso
    //una señal (normalmente mediante kill)
    pause();
    printf("hola mundo 2\n");
    return 0;
}
