#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    fork();
    fork();
    printf("Hola. PID: %d\n", getpid());
    return 0;
}
