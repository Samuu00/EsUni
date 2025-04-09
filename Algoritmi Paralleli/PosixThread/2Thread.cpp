#include <iostream>
#include <pthread.h>
#include <vector>
using namespace std;

int nTreads = 2;

void run(void* arg) {
    sleep(1);
    int i = *(int*)arg;
    printf( %d!"\n", i);
    return NULL;
}

int main() {
    vector<pthread_t> threads(nTreads);
    for(int i = 0; i < nTreads; i++) {
        int* p = new int(i);
        pthread_create(&threads[i], NULL, run, p);
    }
    for(int i  = 0; i < nTreads; i++) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}
