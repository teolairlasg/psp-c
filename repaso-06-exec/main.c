#include <unistd.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    
    pid_t pid_execl = fork();
    if (pid_execl == 0){
        printf("Exec L --------------\n\n");
        execl("ls", "ls", "-l", "-a", NULL);
    }else{
        sleep(1);
        printf("Exec V --------------\n\n");
        char* argumentos[] = {"ls", "-l", "-a", NULL};
        execv("/bin/ls",argumentos);
    }
    return 0;

}
