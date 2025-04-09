#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int n = 1000000;
int num = 0;

void* run(void * arg){
	for(int i=0;i<n;i++){
		num++;
	}
	return NULL;
}

int main(int arg, char* argv[]){
    
	pthread_t thid0,thid1;

	int ris = pthread_create(&thid0, NULL, &run, NULL);
	ris = pthread_create(&thid1, NULL, &run, NULL);
	
	pthread_join(thid0, NULL);
	pthread_join(thid1, NULL);
	printf("num = %d\n", num);
}