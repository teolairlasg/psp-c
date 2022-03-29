#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
// esta librería incluye la funcionalidad de los booleanos
#include <stdbool.h>
#define MAX_HIJOS 100

/*
    Cuando hayas terminado haz el repaso-04, que consistirá en el mismo programa
    pero usando un bucle para esperar a n hijos que vendrán dados por el parámetro
    de entrada al programa
*/

int main(int argc, char const *argv[])
{
    if(argc != 2){
        printf("Número de parámetros incorrecto:\n");
        printf("\t Uso: %s núm_hijos \n",argv[0]);
        exit(-1);
    }
    int num_hijos = atoi(argv[1]);
    if(num_hijos <= 0 || num_hijos > 100){
        printf("Número de hijos incorrecto:\n");
        printf("\t Uso: %s núm_hijos \n",argv[0]);
        printf("El programa admite números entre 1 y %d\n",MAX_HIJOS);
        exit(-2);
    }
    pid_t pidHijo;
    for (int i = 1; i <= num_hijos; i++)
    {
        pidHijo = fork();
        if(pidHijo == 0){ //código de todos los hijo
            printf("[Hijo %d]: Mi pid es %d y el de mi padre %d\n", i, getpid(), getppid());
            return i;
        }
    }
    // este es sólo código del padre porque los hijos han salido en el return
    int estado;
    for (int i = 1; i < num_hijos; i++){
        pidHijo = wait(&estado);
                    if (WIFEXITED(estado) == false){
                printf("[Padre]: ¡El hijo %d terminó mal!\n", pidHijo);
            }else{
                printf("[Padre]: El hijo %d terminó con estado %d\n",
                             pidHijo, WEXITSTATUS(estado));
            }
    }
    // a este return sólo debería llegar el padre
    return 0;
}
