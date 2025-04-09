#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int n = 10000000;
pthread_mutex_t mutex;
int num = 0;

void* run(void * arg){
	for(int i=0;i<n;i++){
		pthread_mutex_lock(&mutex);	 
		num++;
		pthread_mutex_unlock(&mutex);  
	}
	return NULL;
}

int main(int arg, char* argv[]){

	pthread_t thid0,thid1;
	pthread_mutex_init(&mutex, NULL);

	int ris = pthread_create(&thid0, NULL, &run, NULL);
	ris = pthread_create(&thid1, NULL, &run, NULL);
	
	pthread_join(thid0, NULL);
	pthread_join(thid1, NULL);
	pthread_mutex_destroy(&mutex);
	printf("num = %d\n", num);
}
