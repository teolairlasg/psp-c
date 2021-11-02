#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/wait.h>

void tratarSenyal(int cod_senyal);

int main(int argc, char const *argv[])
{
    pid_t pidHijo1, pidHijo2;
    printf("[Padre]: PID: %d\n", getpid());
    if ((pidHijo1 = fork()) == -1)
    {
        perror("Error creando un hijo");
        exit(-1);
    }

    if (pidHijo1 == 0)
    { //hijo1
        signal(SIGUSR1, tratarSenyal);
        printf("[Hijo 1]: pid: %d\n", getpid());
        pause(); //Espero a una señal
    }
    else
    { //padre
        printf("[Padre]: he creado un hijo con pid %d\n", pidHijo1);
        if ((pidHijo2 = fork()) == -1)
        {
            perror("Error creando un hijo");
            exit(-1);
        }

        if (pidHijo2 == 0)
        { //hijo2
            printf("[Hijo 2]: pid: %d\n", getpid());
            sleep(2);
            kill(pidHijo1,SIGUSR1);
        }
        else
        {
            printf("[Padre]: he creado un hijo con pid %d\n", pidHijo2);
            printf("[Padre]: Esperando a un hijo.\n");
            printf("[Padre]: El hijo con pid %d finalizó\n", wait(NULL));
            printf("[Padre]: Esperando a otro hijo.\n");
            printf("[Padre]: El hijo con pid %d finalizó\n", wait(NULL));
        }
    }
    return 0;
}

void tratarSenyal(int cod_senyal){
    printf("[Proceso %d]: He recibido una señal\n",getpid());
}