#include <iostream>
#include <pthread.h>
#include <vector>
#include <unistd.h> 
using namespace std;

int nThreads = 100;

void* run(void* arg) {
    sleep(1);
    int i = *(int*)arg;
    printf("%d\n", i);
    delete (int*)arg; 
    return NULL;
}

int main() {
    vector<pthread_t> threads(nThreads);
    for (int i = 0; i < nThreads; i++) {
        int* p = new int(i);
        pthread_create(&threads[i], NULL, &run, (void*)p); 
    }
    for (int i = 0; i < nThreads; i++) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}
