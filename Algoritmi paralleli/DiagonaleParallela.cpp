#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int my_rank, nproc;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &nproc);

    int n;
    int *m = nullptr;
    int *m2 = nullptr;

    if (my_rank == 0) {
        scanf("%d", &n);
    }
    MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);

    m = new int[n * n];
    m2 = new int[n * n]();  

    MPI_Datatype send_DT, recv_DT;

    MPI_Type_vector(n, 1, n+1, MPI_INT, &send_DT);
    MPI_Type_commit(&send_DT);

    MPI_Type_vector(n, 1, n-1, MPI_INT, &recv_DT);
    MPI_Type_commit(&recv_DT);

    if (my_rank == 0) {
        printf("Matrice iniziale:\n");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                m[i * n + j] = rand() % 100;
                printf("%3d ", m[i * n + j]);
            }
            printf("\n");
        }
        MPI_Send(m, 1, send_DT, 1, 0, MPI_COMM_WORLD);
    }

    if (my_rank == 1) {
        MPI_Recv(m2 + (n - 1), 1, recv_DT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        printf("Matrice m2 con diagonale inversa:\n");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%3d ", m2[i * n + j]);
            }
            printf("\n");
        }
    }

    delete[] m;
    delete[] m2;

    MPI_Finalize();
    return 0;
}
