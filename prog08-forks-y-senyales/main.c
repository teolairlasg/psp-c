#include <unistd.h>  //define la función fork
#include <sys/types.h> //define el tipo pid_t
#include <sys/wait.h> //define la función wait y waitpid
#include <signal.h> //define la función signal y los códigos SIGUSR1...
#include <stdio.h>  //define la función printf
#include <stdlib.h>  //define la función exit

//declaramos el manejador de la señal
void manejadorHijo(int num_senyal);
void manejadorPadre(int num_senyal);

int main(int argc, char const *argv[])
{
    pid_t pid;
    pid = fork();
    if (pid == -1){ //gestionamos un posible error
        perror("Error en el fork");
        exit(1);
    }
    if(pid == 0){ //Soy el proceso hijo
        signal(SIGUSR1, manejadorHijo);
        printf("[Proceso: %d]: Manejador activado.\n",getpid());
        pause();
    }else{ //soy el padre
        signal(SIGUSR1, manejadorPadre);
        printf("[Proceso: %d]: Manejador activado.\n",getpid());
        pause();
        pid_t pid_hijo = wait(NULL);
    }
    return 0;
}

//implementamos los manejadores
void manejadorHijo(int num_senyal){
    printf("Soy el manejador de la señal del hijo.\n");
}
void manejadorPadre(int num_senyal){
    printf("Soy el manejador de la señal del padre.\n");
};