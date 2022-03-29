
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

void manejadorSenyal(int);

int main(int argc, char const *argv[])
{
    int fd;
    // int fd[2];
    // FIFO file path
    char *myfifo = "/tmp/myfifo";

    // Creamos el FIFO
    // mkfifo(<pathname>, <permission>)
    //pipe(fd);
    mkfifo(myfifo, 0666);

    signal(SIGUSR1, manejadorSenyal);

    pid_t hijo = fork();
    if (hijo == -1)
    {
        perror("error en el fork");
        exit(1);
    }
    else if (hijo == 0) //codigo hijo
    {
        //cerramos el descriptor de escritura
        //close(fd[1]);
        sleep(1);
        kill(getppid(), SIGUSR1);
        fd = open(myfifo, O_RDONLY);
        pid_t abuelo;
        read(fd, &abuelo, sizeof(pid_t));
        printf("[Hijo]: Mi pid es %d, mi padre es %d, mi abuelo es %d\n", getpid(), getppid(), abuelo);
        
    }
    else //codigo padre
    {
        //cerramos el descriptor de lectura
        //close(fd[0]);
        pause();
        fd = open(myfifo, O_WRONLY);
        pid_t pidPadre = getppid();
        write(fd, &pidPadre, sizeof(pidPadre));
        int status;
        wait(&status);
        printf("[Padre]: El hijo %d, acabó con estado %d\n", hijo, WEXITSTATUS(status));
    }
    return(0);
}

void manejadorSenyal(int senyal)
{
    printf("[Proceso %d]: He recibido la señal %d\n", getpid(), senyal);
}
