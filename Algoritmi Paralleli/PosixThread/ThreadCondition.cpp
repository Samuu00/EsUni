#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

pthread_mutex_t mutexFuel;
pthread_cond_t condFuel;
int fuel = 0;

void* fuel_filling(void* arg) { //try 2 filler each one of 60 and 3 cars
    for (int i = 0; i < 2; i++) {
        pthread_mutex_lock(&mutexFuel);
        fuel += 60;
        printf("Filled fuel... %d\n", fuel);
        pthread_mutex_unlock(&mutexFuel);
        pthread_cond_broadcast(&condFuel);
        sleep(1);
    }
    return NULL;
}

void* car(void* arg) {
    pthread_mutex_lock(&mutexFuel);
    while (fuel < 40) {
        printf("No fuel. Waiting...\n");
        pthread_cond_wait(&condFuel, &mutexFuel);
    }
    fuel -= 40;
    printf("Got fuel. Now left: %d\n", fuel);
    pthread_mutex_unlock(&mutexFuel);
    return NULL;
}

int main(int argc, char* argv[]) {
    pthread_t thFuel,thCar[3];
    pthread_mutex_init(&mutexFuel, NULL);
    pthread_cond_init(&condFuel, NULL);
    
    pthread_mutex_init(&mutexFuel, NULL);
    
    pthread_create(&thFuel, NULL, &fuel_filling, NULL);
    for (int i = 0; i < 3; i++)
        pthread_create(&thCar[i], NULL, &car, NULL);
    
    pthread_join(thFuel, NULL);
    for (int i = 0; i < 3; i++)
        pthread_join(thCar[i], NULL);
    pthread_mutex_destroy(&mutexFuel);
    pthread_cond_destroy(&condFuel);
    return 0;
}