#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    int a = 3;
    pid_t pid = fork();
    if(pid == 0){ //Proceso hijo
        printf("[Hijo]: Mi PID es: %d\n\tVariable a: %d\n",getpid(),a);
        printf("[Hijo]: El pid de mi padre es %d\n", getppid());
        sleep(1);
    }else{ //El proceso padre
        int estado_hijo = -4;
        printf("[Padre]: Mi PID es: %d\n\tVariable a: %d\n",getpid(),a);
        printf("[Padre]: El pid de mi padre es %d\n", getppid());
        printf("[Padre]: El hijo %d ha terminado \n",wait(&estado_hijo));
        //El estado guarda más cosas en el mismo entero además del código de retorno
        //hay que usar macros para extraer del "entero" los valores que se pretenden
        printf("[Padre]: El estado de finalización ha sido: %d\n",WIFEXITED(estado_hijo));    
        }
    //parte común a ambos procesos
    return 2;
}
