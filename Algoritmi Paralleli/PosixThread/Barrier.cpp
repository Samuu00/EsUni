#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <ctime>
#include <cerrno>
using namespace std;

const int numThreads = 5;
const int timeoutMs = 5;  

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

int count = 0;
int generation = 0;
timespec start_time;

void doSomething() {
    sleep(1); 
}

void* BarrierThread() {
    pthread_mutex_lock(&mutex);
    int my_generation = generation;
    count++;
    if (count == numThreads) {
        generation++;
        count = 0;
        pthread_cond_broadcast(&cond);
    } else {
        timespec timeout;
        clock_gettime(CLOCK_REALTIME, &timeout);
        timeout.tv_sec += timeoutMs / 1000;
        timeout.tv_nsec += (timeoutMs % 1000) * 1000000;
        while (my_generation == generation) {
            int res = pthread_cond_timedwait(&cond, &mutex, &timeout);
            if (res == ETIMEDOUT) {
                cout << "Timeout in un thread" << endl;
                break;
            }
        }
    }

    pthread_mutex_unlock(&mutex);
    return NULL;
}

void BarrierWithoutTimeout() {
    pthread_mutex_lock(&mutex);
    int my_generation = generation;
    count++;
    if (count == numThreads) {
        generation++;
        count = 0;
        pthread_cond_broadcast(&cond);
    } else {
        while (my_generation == generation) {
            pthread_cond_wait(&cond, &mutex);
        }
    }
    pthread_mutex_unlock(&mutex);
}

void* ThreadFunction(void* arg) {
    printf("Inizio\n");
    for (int i = 1; i < 5; i++) {
        doSomething();
        BarrierThread();
        printf("BarrierThread %d\n", i);
    }
    doSomething();
    BarrierThread();
    printf("Fine\n");
    return NULL;
}

int main(int argc, char* argv[]) {
    pthread_t threads[numThreads];

    for (int i = 0; i < numThreads; i++) {
        pthread_create(&threads[i], NULL, ThreadFunction, NULL);
    }

    for (int i = 0; i < numThreads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
