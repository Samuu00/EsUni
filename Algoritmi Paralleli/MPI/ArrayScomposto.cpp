#include <iostream>
#include <mpi.h>
#define MAXSIZE 100000000

int main(int argc, char* argv[]){
    double *data = NULL;
    int rank, numproc, mysize, i, source, low, high;
    MPI_Status status;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &numproc);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    mysize = MAXSIZE / numproc;
    low = rank * mysize;
    double myresult = 0;
    double result = 0;
    data = new double[mysize];
    int value = low;

    for(i = 0; i < mysize; i++){
        data[i] = value + i;
    }
    MPI_Barrier(MPI_COMM_WORLD);
    double startTime = MPI_Wtime();

    for(i = 0; i < mysize; i++){
        myresult += data[i];
    }

    if (rank == 0){
        result = myresult;
        for(source = 1; source < numproc; source++){
            MPI_Recv(&myresult, 1, MPI_DOUBLE, source, 0, MPI_COMM_WORLD, &status);
            result += myresult;
        }

    } else {
        MPI_Send(&myresult, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);
    }
    MPI_Barrier(MPI_COMM_WORLD);
    double endTime = MPI_Wtime();

    if (rank == 0){
        printf("Somma: %e\n", result);
        printf("Tempo impiegato: %f\n", 1000*(endTime - startTime));
    }

    delete[] data;
    MPI_Finalize();
    return 0;
}
