#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int my_rank, nproc;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &nproc);

    int* m = new int[n*n];

    MPI_Datatype send_DT;
    MPI_Datatype recv_DT;
    MPI_Type_vector(n, 1, n+1, MPI_INT, &send_DT);
    MPI_Type_vector(n, 1, n-1, MPI_INT, &recv_DT);
    
    if (my_rank == 0) {
        MPI_Send(m, 1, send_DT, 1, 0, MPI_COMM_WORLD);
    }
    else {
        MPI_Status status;
        MPI_Recv(m+n-1, 1, recv_DT, 0, 0, MPI_COMM_WORLD, &status);
    }

    MPI_Type_free(&send_DT);
    MPI_Type_free(&recv_DT);

    MPI_Finalize();
    return 0;

}