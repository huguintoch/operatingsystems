#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <strings.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

extern int h_errno;

struct hostent *gethostbyname(const char *name);

int main(int argc, char **argv) {
    char *hostName = argv[1];
    char *message = "GET / HTTP/1.0\r\n\r\n";
    char c;

    struct sockaddr_in serverAddress;
    struct hostent *serverInfo = gethostbyname(hostName);
    bzero(&serverAddress, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(80);
    // serverAddress.sin_addr = serverInfo->h_addr_list[0]; // error por copia de tipo no reconocido
    bcopy((char *) serverInfo->h_addr, 
        (char *)&serverAddress.sin_addr.s_addr, serverInfo->h_length);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    connect(sockfd, (const struct sockaddr *)&serverAddress, sizeof(serverAddress));

    write(sockfd, message, strlen(message));
    while(read(sockfd, &c, 1)){
        printf("%c",c);
    }

    close(sockfd);
    printf("\n");

    return 0;
}