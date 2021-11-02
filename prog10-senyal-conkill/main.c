#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdbool.h>

void tratarSenyal(int cod_senyal);

pid_t pidHijo; //variable global para poder ser utilizada
                //desde el main y tb desde la función.
bool final = false;

int main(int argc, char const *argv[])
{
    pidHijo = fork();
    switch (pidHijo)
    {
    case -1:
        exit(1);
        break; 
    case 0: //hijo
        signal(SIGUSR2, tratarSenyal);
        signal(SIGINT, SIG_IGN); //IGNORAMOS SEÑAL CTRL-C
        printf("[Hijo %d]: Esperando señal\n", getpid());
        while(!final){
            printf("[Hijo]: Esperando 5 segundos...\n");
            sleep(5);
        }
        break;
    default: //padre
        signal(SIGINT, tratarSenyal);
        printf("[Padre %d]: Esperando señal\n", getpid());
        pause();
        wait(NULL); //esperar al hijo
    }


    return 0;
}

void tratarSenyal(int cod_senyal){
    if (cod_senyal == SIGINT){
        printf("[Proceso %d]: recibida señal %d\n", getpid(), cod_senyal);
        printf("Enviando señal al hijo con pid %d en 3 segundos\n", pidHijo);
        sleep(3);
        kill(pidHijo, SIGUSR2);
    }else if(cod_senyal == SIGUSR2){
        printf("[Proceso %d]: recibida señal %d\n", getpid(), cod_senyal);
        final=true;        
    }
}
