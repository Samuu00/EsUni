#include <iostream>
#include <pthread.h>
using namespace std;

void* run(void* arg) {
    cout << "Hello from thread!" << endl;
    return NULL;
}

int main() {
    pthread_t thread;
    //Creazione del thread, il secondo argomento è NULL perchè non ci sono parametri da passare alla funzione run
    //Il terzo argomento è la funzione da eseguire, il quarto è NULL perchè run ritorna void* e non ha bisogno di argomenti
    pthread_create(&thread, NULL, &run, NULL);
    //Parameter: idThread, puntatore a puntatore del ritorno della funzione;
    pthread_join(thread, NULL);
    //Il join aspetta che il thread finisca prima di continuare l'esecuzione del main
    return 0;
}
