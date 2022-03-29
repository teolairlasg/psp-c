#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
// esta librería incluye la funcionalidad de los booleanos
#include <stdbool.h>

int main(int argc, char const *argv[])
{
    int num = 45;
    printf("Inicio de programa mi PID es: %d\n", getpid());
    printf("Inicio de programa mi padre es: %d\n", getppid());
    pid_t pid = fork();
    if(pid == -1){
        printf("Error en el fork();\n");
        exit(-1);
    }else if(pid == 0){
        printf("[Hijo] mi PID es: %d\n", getpid());
        printf("[Hijo] mi Padre es: %u\n", getppid());
        num--;
        printf("[Hijo]: Valor de num: %d\n", num);
        sleep(15);
        return 3;
    }else{
        printf("[Padre] mi PID es: %d\n", getpid());
        printf("[Padre] mi hijo es: %d\n", pid);
        num++;
        printf("[Padre]: Valor de num: %d\n", num);
        printf("[Padre]: Esperando al hijo...\n");
        int estado;
        wait(&estado);
        if( WIFEXITED(estado) == false ){
            printf("[Padre]: El hijo ha terminado mal!!\n");
        }else{
            printf("[Padre]: El hijo acabó bien con estado %d\n", WEXITSTATUS(estado));
        }
        return 0;
    }
}
