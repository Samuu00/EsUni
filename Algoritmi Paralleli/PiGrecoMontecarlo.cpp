#include <iostream>
#include <mpi.h>
#include <cstdlib>
using namespace std;

int main(int argc, char *argv[]){
    int rank, num_procs;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &num_procs);

    int num_points = atoi(argv[1]);
    int points_per_process = num_points / num_procs;
    int points_inside_circle = 0;
    int total_points_inside_circle = 0;
    double x, y;

    MPI_Barrier(MPI_COMM_WORLD);
    double start_time = MPI_Wtime();

    for(int i = 0; i < points_per_process; i++){
        x = (double)rand() / RAND_MAX;
        y = (double)rand() / RAND_MAX;
        if(x * x + y * y <= 1.0){
            points_inside_circle++;
        }
    }

    if(rank != 0){
        MPI_Send(&points_inside_circle, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }else{
        MPI_Status status;
        total_points_inside_circle = points_inside_circle; 
        for(int i = 1; i < num_procs; i++){
            int recv_points;
            MPI_Recv(&recv_points, 1, MPI_INT, i, 0, MPI_COMM_WORLD, &status);
            total_points_inside_circle += recv_points;
        }
    }

    double end_time = MPI_Wtime();

    if(rank == 0){
        double pi = (double)total_points_inside_circle / num_points * 4.0;
        cout << "Estimated value of Pi: " << pi << endl;
        cout << "Elapsed time: " << 1000 * (end_time - start_time) << " ms" << endl;
        cout << "Speedup: " << (1000 * (end_time - start_time) / (num_procs * (end_time - start_time))) << " ms" << endl;
    }

    MPI_Barrier(MPI_COMM_WORLD);
    MPI_Finalize();
    return 0;
}
