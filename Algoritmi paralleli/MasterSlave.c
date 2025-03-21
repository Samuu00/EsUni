#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "mpi.h"

int main(int argc, char** argv) {
    int my_rank; 
    int nproc;  

    MPI_Status status; 

    MPI_Init(&argc, &argv);                  
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank); 
    MPI_Comm_size(MPI_COMM_WORLD, &nproc);   

    if (my_rank != 0) { 
        int rnd = rand() % 10;
        printf("Slave: Rank %d send %d\n", my_rank, rnd);
        MPI_Send(&rnd, 1, MPI_INT, 0, 11, MPI_COMM_WORLD);
    } else { 
        int sum = 0;
        for (int source = 1; source < nproc; source++) {
            int rec;
            MPI_Recv(&rec, 1, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
            sum += rec;
        }
        printf("Master sum is %d, of rank %d\n", sum, my_rank);
    }

    MPI_Finalize();
    return 0;
}
