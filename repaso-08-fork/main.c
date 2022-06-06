

// hacer 100 hijos en bucle que saluden
// tras acabar con el último hijo, esperarlos a todos.
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>


int main(int argc, char const *argv[])
{
    pid_t pid;
    for (int i = 0; i < 100; i++)
    {
        pid = fork();
        if (pid == 0 ){
            printf("[PID: %d]: Hola mundo!\n",getpid());
            return i;
        }
    }

    for (int i = 0; i < 100; i++)
    {
        int estadoHijo;
        wait(&estadoHijo);
        printf("El hijo %d ha acabado\n",
                    WEXITSTATUS(estadoHijo));
    }
        
    printf("Programa terminado\n");

    return 0;
}
