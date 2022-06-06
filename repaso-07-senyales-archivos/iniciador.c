//programa que espera un segundo, crea un archivo vacío y envía una señal SIGUSR1 a un pid pasado por parámetro
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
int main(int argc, char const *argv[])
{
    pid_t proceso_escritor = atoi(argv[1]);
    sleep(1);
    system("touch /tmp/archivo.txt");
    kill(proceso_escritor, SIGUSR1);
    return 0;
}
