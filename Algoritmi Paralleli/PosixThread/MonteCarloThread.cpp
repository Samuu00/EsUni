#include <iostream>
#include <pthread.h>
#include <unistd.h>
using namespace std;

const int numThreads = 5;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* PiGrecoMonteCarlo(void* arg){
    int numIterazioni = *(int*)arg;
    int dentro = 0;
    for(int i = 0; i < numIterazioni; i++){
        pthread_mutex_lock(&mutex);
        double x = (double)rand() / RAND_MAX;
        double y = (double)rand() / RAND_MAX;
        if(x * x + y * y <= 1){
            dentro++;
        }
        pthread_mutex_unlock(&mutex);
    }
    double* result = new double(dentro);
    double pi = 4.0 * dentro / numIterazioni;
    *result = pi;
    return (void*)result;
}

int main(int argc, char* argv[]){
    pthread_t threads[numThreads];
    int numIterazioni = 10000; 
    double piTotale = 0.0;
    
    for(int i = 0; i < numThreads; i++){
        pthread_create(&threads[i], NULL, PiGrecoMonteCarlo, &numIterazioni);
    }
    
    for(int i = 0; i < numThreads; i++){
        void* result;
        pthread_join(threads[i], &result);
        piTotale += *(double*)result;
        delete (double*)result;
    }
    
    piTotale /= numThreads;
    cout << "Valore di Pi Greco: " << piTotale << endl;
    
    pthread_mutex_destroy(&mutex);
    return 0;
}


