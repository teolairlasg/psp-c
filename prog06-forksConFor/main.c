//Crear un programa que usando 2 bucles
// cree 5 hijos definidos en una constante
//N_HIJOS.
//Cada uno de los hijos (el padre NO) debe imprimir su pid y el 
// de su padre y esperar un segundo con sleep
//Después de crear los hijos el padre (sólo el padre)
//se quedará esperando en otro bucle
//al mismo número de hijos a que terminen.
//al final el padre (sólo el padre) imprimirá un mensaje
//"soy PID, todos mis hijos han terminado"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

#define N_HIJOS 5

int main(int argc, char const *argv[])
{
    pid_t pid_padre = getpid();
    pid_t pid;
    for (int i = 0; i < N_HIJOS && pid_padre == getpid(); i++)
    {
        pid = fork();
        printf("[Padre %d]: Proceso hijo %d creado.\n", getpid(), pid);
    }
    if (getpid()==pid_padre){ //solo el padre
        int estado_proceso;
        pid_t pid_hijo;
        //proceso padre espera a los hijos
        for (int i = 0; i < N_HIJOS; i++)
        {
            pid_hijo=wait(&estado_proceso);
            printf("[Padre %d]: Hijo %d ha terminado.\n", getpid(),pid_hijo);    
        }
        printf("[Padre %d]: Todos mis procesos hijo han terminado.\n", getpid());
    }else{  //sólo hijos
        printf(" [Hijo %d]: Mi padre es %d.\n",getpid(), getppid());
        sleep(1);
    }   
    return 0;
}







