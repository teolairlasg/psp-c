#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
// esta librería incluye la funcionalidad de los booleanos
#include <stdbool.h>

int main(int argc, char const *argv[])
{
    pid_t pidProceso = atoi(argv[1]);
    kill(pidProceso, SIGINT);
    return 0;
}
