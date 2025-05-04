#include <iostream>
#include <pthread.h>
#include <unistd.h>
using namespace std;

const int numThreads = 1;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int antArray[10] = {0, 0, 1, 0, 0, 0, 0, 0, 0, 0}; 

void* formicaThread(void* arg) {
    int id = *(int*)arg;
    for (int i = 0; i < 10; i++) {
        pthread_mutex_lock(&mutex);
        if (antArray[i] == 1) {
            antArray[i] = 0; 
            if (i + 1 < 10) {
                antArray[i + 1] = 1; 
            } else {
                antArray[0] = 1; 
            }
        }
        pthread_mutex_unlock(&mutex); 
    }
    delete (int*)arg; 
    return NULL;
}

int main(int argc, char* argv[]) {
    pthread_t threads[numThreads];

    for (int i = 0; i < numThreads; i++) {
        int* id = new int(i);
        pthread_create(&threads[i], NULL, formicaThread, id);
    }

    for (int i = 0; i < numThreads; i++) {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < 10; i++) {
        cout << antArray[i] << " ";
    }
    cout << endl;

    pthread_mutex_destroy(&mutex);
    return 0;
}
