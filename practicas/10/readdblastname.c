#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "./student.h"

int main(){
    Student myStudent;
    char lastname[20];
    printf("lastName: ");
    scanf("%s", lastname);

    int fd = open(dbName, O_RDONLY, 0);
    while(read(fd, &myStudent, sizeof(Student))){
        if(strcmp(myStudent.lastName, lastname) == 0){
            printf("id %d, firstName %s, lastName %s, semester %c \n"
            ,myStudent.id, myStudent.firstName, myStudent.lastName, myStudent.semester);
        }
    }
    close(fd);
    return 0;
}