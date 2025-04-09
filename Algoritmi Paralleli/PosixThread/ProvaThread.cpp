#include <iostream>
#include <pthread.h>
using namespace std;

void* run(void* arg) {
    int *p = new int;
    *p = 69;

    return p;
}
int main(int argc, char* argv[]) {
    pthread_t thid;

    pthread_create(&thid, NULL, run, NULL);
    int *ris;
    pthread_join(thid, (void**)&ris);
    printf("Risultato: %d\n", *ris);
    delete ris; 
    return 0;
}