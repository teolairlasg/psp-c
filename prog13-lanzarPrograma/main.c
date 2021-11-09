#include <unistd.h>
#include <stdio.h>
int main(int argc, char const *argv[])
{
    if (execl("./hola.sh","./hola.sh",NULL) == -1){
        perror("Error al ejecutar");
    }
    return 0;
}
