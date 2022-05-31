#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
// esta librería incluye la funcionalidad de los booleanos
#include <stdbool.h>

// cabecera de las funciones gestoras de señal
// se declaran aquí y se implementan debajo del main
// esto es solo una norma estilística, ya que podrían
// ser implementadas aquí directamente.
void funcion_senyal1(int);
void funcion_senyal2(int);

int main(int argc, char const *argv[])
{
    signal(SIGUSR1, funcion_senyal1);
    signal(SIGUSR2, funcion_senyal2);
    signal(SIGINT, funcion_senyal2);
    printf("[%s]: Mi pid es %d\n", argv[0], getpid());
    pause();
    pause();
    printf("[%s]: Señal recibida\n", argv[0]);
    return 0;
}

void funcion_senyal1(int codigo){
    printf("Función señal 1\n");
}

void funcion_senyal2(int codigo){
    printf("Función señal 2, se ha recibido la señal número: %d\n", codigo);
    if(codigo == SIGINT){ // SIGINT es un DEFINE con valor 2
        //devolvemos la señal SIGINT a su comportamiento por defecto.
        signal(SIGINT,SIG_DFL);
    }
}