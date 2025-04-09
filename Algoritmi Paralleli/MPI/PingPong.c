#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

int main(int argc, char *argv[]) {

    int rank, size;
    int rc, count;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int *buf = (int *)malloc(MAXSIZE * sizeof(int));
    for (int i = 0; i < MAXSIZE; i++) {
        buf[i] = i;
    }

    MPI_Status status;

    if (rank == 0) {
        MPI_Send(buf, MAXSIZE, MPI_INT, 1, 17, MPI_COMM_WORLD);
        MPI_Recv(buf, MAXSIZE, MPI_INT, 1, 23, MPI_COMM_WORLD, &status);
        printf("Processor 0 received data from processor 1\n");
    } else if (rank == 1) {
        MPI_Recv(buf, MAXSIZE, MPI_INT, 0, 17, MPI_COMM_WORLD, &status);
        MPI_Send(buf, MAXSIZE, MPI_INT, 0, 23, MPI_COMM_WORLD);
        printf("Processor 1 received data from processor 0\n");
    }

    MPI_Get_count(&status, MPI_INT, &count);
    printf("Task %d : Received %d integers from task %d with tag %d \n", rank, count, status.MPI_SOURCE, status.MPI_TAG);

    MPI_Finalize();
    return 0;
}
