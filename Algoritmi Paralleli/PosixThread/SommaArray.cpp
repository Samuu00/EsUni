#include <iostream>
#include <pthread.h>
#include <unistd.h>
using namespace std;

const int numThreads = 5;
const int n = 100;
const int block = n / numThreads;
int sumArray[n];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* riempiArray(void* arg){
    pthread_mutex_lock(&mutex);
    for(int i = 0; i < n; i++){
        sumArray[i] = i + 1; 
    }
    pthread_mutex_unlock(&mutex);
    return NULL;
}

void* somma(void* arg){
    int id = *(int*)arg;
    int start = id * block;
    int end = (id + 1) * block;
    int sum = 0;
    int* result = new int(sum);
    for(int i = start; i < end; i++){
        pthread_mutex_lock(&mutex);
        sum += sumArray[i];
        pthread_mutex_unlock(&mutex);
    }
    *result = sum;
    delete (int*)arg; 
    return (void*)result;
}

int main(int argc, char* argv[]){
    pthread_t threads[numThreads];
    pthread_t riempiThread;

    pthread_create(&riempiThread, NULL, riempiArray, NULL);
    pthread_join(riempiThread, NULL);
    for(int i = 0; i < numThreads; i++){
        int* id = new int(i);
        pthread_create(&threads[i], NULL, somma, id);
    }
    for(int i = 0; i < numThreads; i++){
        void* sum;
        pthread_join(threads[i], &sum);
        cout << "Somma del thread " << i << ": " << *(int*)sum << endl;
        delete (int*)sum;
    }
    pthread_mutex_destroy(&mutex);
    return 0;
}