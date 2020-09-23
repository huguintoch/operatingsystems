#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
    unsigned pid = fork();
    if(pid == 0){
        // char *newargv[] = { NULL };
        // newargv[0] = argv[1];
        // char *newenviron[] = { NULL };
        printf("Soy el proceso hijo\n");
        execv(argv[1], &argv[1]);
        // execve(argv[1], &argv[1], newenviron);
        return 1;
    }else{
        int status;
        printf("Soy el proceso padre y mi hijo es %u\n", pid);
        // hacer más cosas
        // sleep(4);
        //
        wait(&status);
        printf("Terminando después del hijo y estatus %d\n", status);
    }
    printf("Hola mundo\n");
    return 0;
}