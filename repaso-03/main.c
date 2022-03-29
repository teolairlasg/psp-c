#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
// esta librería incluye la funcionalidad de los booleanos
#include <stdbool.h>

/*
    Este programa creará 2 hijos y esperará los dos imprimendo el número del hijo
    que terminó y el estado con el que terminó.
*/

int main(int argc, char const *argv[])
{
    pid_t hijo1 = fork();
    if (hijo1 == -1)
    {
        perror("Error creando el hijo\n");
        exit(-1);
    }
    else if (hijo1 == 0) // inicio Hijo 1
    {
        printf("[Hijo 1]: Soy %d y mi padre es %d\n", getpid(), getppid());
        return 1;
    } //final Hijo 1
    else
    { // código del padre
        printf("[Padre]: Hijo 1 ha sido creado con pid %d\n", hijo1);
        pid_t hijo2 = fork();
        if (hijo2 == -1)
        {
            perror("Error creando el hijo\n");
            exit(-1);
        }
        else if (hijo2 == 0)
        {
            printf("[Hijo 2]: Soy %d y mi padre es %d\n", getpid(), getppid());
            return 2;
        }
        else
        { // código del padre
            printf("[Padre]: Hijo 2 ha sido creado con pid %d\n", hijo2);
            int estado;
            pid_t hijo_retorno = wait(&estado);
            if (WIFEXITED(estado) == false){
                printf("[Padre]: ¡El hijo %d terminó mal!\n", hijo_retorno);
            }else{
                printf("[Padre]: El hijo %d terminó con estado %d\n",
                             hijo_retorno, WEXITSTATUS(estado));
            }
            hijo_retorno = wait(&estado);
            if (WIFEXITED(estado) == false){
                printf("[Padre]: ¡El hijo %d terminó mal!\n", hijo_retorno);
            }else{
                printf("[Padre]: El hijo %d terminó con estado %d\n",
                             hijo_retorno, WEXITSTATUS(estado));
            }

        }
    }

    return 0;
}
