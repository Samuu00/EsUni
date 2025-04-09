#include <iostream>
#include <mpi.h>
using namespace std;

int main(int argc, char *argv[]){
    MPI_Init(&argc, &argv);
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    int token = 0;

    MPI_Barrier(MPI_COMM_WORLD);
    double start_time = MPI_Wtime();

    if(rank == 0){
        MPI_Send(&token, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        cout << "Process " << rank << " sent token " << token << " to process 1" << endl;
    }else{
        MPI_Status status;
        MPI_Recv(&token, 1, MPI_INT, rank - 1, 0, MPI_COMM_WORLD, &status);
        cout << "Process " << rank << " received token " << token << " from process " << rank - 1 << endl;
        token++;
        if(rank < size - 1){
            MPI_Send(&token, 1, MPI_INT, rank + 1, 0, MPI_COMM_WORLD);
            cout << "Process " << rank << " sent token " << token << " to process " << rank + 1 << endl;
        }
    }

    MPI_Barrier(MPI_COMM_WORLD);
    double end_time = MPI_Wtime();
    
    if(rank == size - 1){
        cout << "Process " << rank << " received final token " << token << " from process " << size - 2 << endl;
    }
    if(rank == 0){
        cout << "Elapsed time: " << 1000 * (end_time - start_time) << " ms" << endl;
    }
    MPI_Finalize();
    return 0;
}