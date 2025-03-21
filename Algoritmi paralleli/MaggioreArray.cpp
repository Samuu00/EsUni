#include <iostream>
#include <mpi.h>
#include <random>
#define MAXSIZE 100

int main(int argc, char* argv[]){ 
    double *data = NULL;
    int rank, numproc, mysize, i, source, low;
    MPI_Status status;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &numproc);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    mysize = MAXSIZE / numproc;  
    low = rank * mysize;         
    data = new double[mysize];   

    
    for(i = 0; i < mysize; i++){
        data[i] = rand() % 100;
    }

    MPI_Barrier(MPI_COMM_WORLD);  
    double startTime = MPI_Wtime();  

    double mymax = data[0];
    for(i = 0; i < mysize; i++){
        if (mymax < data[i]){
            mymax = data[i];
        }
    }

    if (rank == 0){
        double ultimateMax = mymax;
        for(source = 1; source < numproc; source++){
            MPI_Recv(&mymax, 1, MPI_DOUBLE, source, 0, MPI_COMM_WORLD, &status);
            if (ultimateMax < mymax){
                ultimateMax = mymax;
            }
        }
        
        double endTime = MPI_Wtime();  
        printf("Massimo globale: %f\n", ultimateMax);
        printf("Tempo impiegato: %f millisecondi\n", 1000*(endTime - startTime));
    } else {
        
        MPI_Send(&mymax, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);
    }

    delete[] data;  
    MPI_Finalize();  
    return 0;
}
