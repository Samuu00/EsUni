#include <iostream>
#include <pthread.h>
#include <unistd.h>
using namespace std;

pthread_mutex_t mutex;
pthread_cond_t cond;
int currentThread = 0;

void* semaforo(void* arg) {
    int id = *(int*)arg;
    delete (int*)arg;  

    pthread_mutex_lock(&mutex);
    while (id != currentThread) {
        pthread_cond_wait(&cond, &mutex); 
    }

    cout << "Thread " << id << " ha acquisito il semaforo." << endl;
    sleep(2);  

    currentThread++;  
    pthread_cond_broadcast(&cond);  

    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main() {
    int n;
    cin>> n;
    pthread_t threads[n];

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);

    for (int i = 0; i < n; i++) {
        int* p = new int(i);  
        pthread_create(&threads[i], NULL, semaforo, p);
    }

    for (int i = 0; i < n; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    return 0;
}