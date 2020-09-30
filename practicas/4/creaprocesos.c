#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

void signalHandler(int signum){
    int status;
    wait(&status);
    printf("Mi hijo terminó con status %d\n", status);
}

void controlC(int signum){
    printf(" -haha no me matas\n");
}

int main(int argc, char *argv[]){
    signal(2, controlC);
    signal(17, signalHandler);
    unsigned pid = fork();
    if(pid == 0){
        printf("Soy el proceso hijo\n");
        sleep(5);
        // execv(argv[1], &argv[1]);
        return 0;
    }else{
        sleep(2);
        printf("Soy el proceso padre y mi hijo es %u\n", pid);
        // haciendo su chamba
        while(1){
            sleep(2);
            printf("Trabajando...\n");
        }
    }
    printf("Hola mundo\n");
    return 0;
}