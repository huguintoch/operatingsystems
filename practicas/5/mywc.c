#include <stdio.h>
#include <unistd.h>

int main(){
    char c, prev = '\n';
    unsigned lineas = 0, palabras = 0, caracteres = 0;

    while(read(STDIN_FILENO, &c, 1) != 0) {
        caracteres++;
        if (c == '\n') {
            lineas++;
        } else if (c != ' ' && (prev == '\n' || prev == ' ')) {
            palabras++;
        }
        prev = c;
    };

    printf("      %u       %u       %u\n", lineas, palabras, caracteres);
    return 0;
}