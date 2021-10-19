#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    //declaramos una variable de tipo pid_t
    //pid_t en realidad es un número, pero 
    //tiene su propio tipo para poder se independiente del
    //sistema operativo
    pid_t pid;
    
    // cogemos el primer parámetro y lo pasamos a número con atoi
    // (porque viene como texto)
    pid = atoi(argv[1]);
    
    printf("%d", pid);
    //enviamos una señal al proceso con PID pid 
    // de tipo SIGINT (la misma que ctrl-C)
    kill(pid,SIGINT);
    return 0;
}
