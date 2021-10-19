#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void gestionar_interrupcion(int senyal){
    printf("Recibida la señal número %d\n", senyal);
}

int main(int argc, char const *argv[])
{
    signal(SIGINT, gestionar_interrupcion);
    printf("hola mundo\n");
    sleep(30);
    printf("hola mundo 2\n");
    return 0;
}
