#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

//Compile and link with -pthread

typedef struct td {
	int hid;
	char *msg;
} ThreadData;

void * hello(void *arg) {
	ThreadData *td = (ThreadData *)arg;
	printf("%s %d\n", td->msg,td->hid);
	free(arg);
	pthread_exit(NULL);
}

int main() {
	pthread_t newThread;
	
	for(int i=0; i<10; i++) {
		ThreadData *td = (ThreadData *)calloc(1,sizeof(ThreadData));
		td->hid = i;
		td->msg = "Hello desde el hilo";
		pthread_create(&newThread, NULL, hello, (void *)td);
	}
	
	pthread_exit(NULL);	
	return 0;
}