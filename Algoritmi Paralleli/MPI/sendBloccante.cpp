#include <iostream>
#include <mpi.h>

int main(int argc, char *argv[]){
    int rank, size;
    MPI_Status status;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    int MAXSIZE = atoi(argv[1]);
    int* buf = new int[MAXSIZE];
    MPI_Request request;

    for(int i = 0; i < MAXSIZE; i++){
        if(rank == 0){
            MPI_Isend(buf, MAXSIZE, MPI_INT, 1, 17, MPI_COMM_WORLD, &request);
            MPI_Recv(buf, MAXSIZE, MPI_INT, 1, 23, MPI_COMM_WORLD, &status);
        } else if(rank == 1){
            MPI_Isend(buf, MAXSIZE, MPI_INT, 0, 23, MPI_COMM_WORLD, &request);
            MPI_Recv(buf, MAXSIZE, MPI_INT, 0, 17, MPI_COMM_WORLD, &status);
            
        }
    }

    delete[] buf;
    MPI_Finalize();
    printf("Terminato processo: %d \n", rank);

    return 0;
}
