#include "mpi.h"
#include <stdio.h>

int main(int argc, char *argv[]) {

    int rank, size;
    int max = 2;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0) {
        max = 0;
        printf("Hello from max master: %d\n", max);
    }
    else {
        max = 1;
        printf("Hello from max slave: %d\n", max);
    }

    printf("Hello from outside: %d\n", max);
    
    MPI_Finalize();
    return 0;
}
