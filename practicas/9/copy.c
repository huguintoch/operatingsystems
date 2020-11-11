
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv){
    char *srcFile = argv[1];
    char *destFile = argv[2];

    int fd = open(srcFile, O_RDONLY, 0);
    if(fd < 0){
        printf("Error al abrir el archivo \n");
        return 1;
    }
    int dFd = open(destFile, O_WRONLY | O_CREAT, 0600);
    char c;
    while(read(fd, &c, 1)){
        write(dFd,&c,1);
    }
    close(fd);
    close(dFd);
    return 0;
}