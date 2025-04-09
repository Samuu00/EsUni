#include <iostream>
#include <mpi.h>
#include <cstdlib>
using namespace std;

#define v(r, c) (r * n + c)

int main(int argc, char *argv[]) {
    MPI_Init(&argc, &argv);
    
    int rank, num_procs;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &num_procs);

    int n = atoi(argv[1]);
    int *matrix = new int[n * n];
    int block = n / num_procs;

    MPI_Barrier(MPI_COMM_WORLD);
    double start_time = MPI_Wtime();

    if (rank == 0) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[v(i, j)] = rand() % 1000;
            }
        }
    }

    MPI_Bcast(matrix, n * n, MPI_INT, 0, MPI_COMM_WORLD);

    int max_val_local = 0;
    for (int i = rank * block; i < (rank + 1) * block; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[v(i, j)] > max_val_local) {
                max_val_local = matrix[v(i, j)];
            }
        }
    }

    if (rank != 0) {
        MPI_Send(&max_val_local, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    } else {
        int max_val_global = max_val_local;
        MPI_Status status;
        for (int i = 1; i < num_procs; i++) {
            int max_val_received;
            MPI_Recv(&max_val_received, 1, MPI_INT, i, 0, MPI_COMM_WORLD, &status);
            if (max_val_received > max_val_global) {
                max_val_global = max_val_received;
            }
        }
        double end_time = MPI_Wtime();
        cout << "Max value: " << max_val_global << endl;
        cout << "Elapsed time: " << 1000 * (end_time - start_time) << " ms" << endl;
    }

    MPI_Barrier(MPI_COMM_WORLD);
    delete[] matrix;
    MPI_Finalize();
    return 0;   
}
