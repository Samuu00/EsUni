#include <iostream>
#include <mpi.h>
#include <vector>
using namespace std;

int main(int argc, char *argv[]){
    MPI_Init(&argc, &argv);
    int rank, num_procs;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &num_procs);

    int n = atoi(argv[1]);
    vector<int> A(n), B(n);
    int block = n / num_procs;
    int moltiplicazione = 0;
    int prodottoScalare = 0;

    if(rank == 0){
        for(int i = 0; i < n; i++){
            A[i] = rand() % 1000;
            B[i] = rand() % 1000;
        }
    }
    MPI_Bcast(A.data(), n, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(B.data(), n, MPI_INT, 0, MPI_COMM_WORLD);
    
    MPI_Barrier(MPI_COMM_WORLD);
    double start_time = MPI_Wtime();

    for(int i = 0; i < block; i++){
        moltiplicazione += A[rank * block + i] * B[rank * block + i];
    }

    if(rank != 0){
        MPI_Send(&moltiplicazione, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }else{
        MPI_Status status;
        prodottoScalare = moltiplicazione;
        int recv_moltiplicazione;
        for(int i = 1; i < num_procs; i++){
            MPI_Recv(&recv_moltiplicazione, 1, MPI_INT, i, 0, MPI_COMM_WORLD, &status);
            prodottoScalare += recv_moltiplicazione;
        }
    }

    if(rank == 0){
        double end_time = MPI_Wtime();
        cout << "Prodotto scalare: " << prodottoScalare << endl;
        cout << "Tempo impiegato: " << 1000 * (end_time - start_time) << " ms" << endl;
        cout << "Speedup: " << (1000 * (end_time - start_time) / (num_procs * (end_time - start_time))) << " ms" << endl;
    }

    MPI_Barrier(MPI_COMM_WORLD);
    MPI_Finalize();
    return 0;
}