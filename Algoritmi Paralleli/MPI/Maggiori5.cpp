#include <iostream>
#include <mpi.h>
#include <cstdlib>
#include <ctime>   

#define MAXSIZE 100

void calc_max5(int* data, int size_data, int* max_5){

    for(int i = 0; i < 5; i++){
        int maxIndex = i;
        for(int j = i+1; j < size_data; j++){
            if(data[j] > data[maxIndex]){
                maxIndex = j;
            }
        }
        int temp = data[i];
        data[i] = data[maxIndex];
        data[maxIndex] = temp;
        max_5[i] = data[i];
    }
}

int main(int argc, char* argv[]){
    int *data = NULL;
    int rank, numproc, mysize, i, source;
    MPI_Status status;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &numproc);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    mysize = MAXSIZE / numproc;
    data = new int[mysize];

    int* max_5 = new int[5];
    int* max5_all = new int[5 * numproc]; 

    for(i = 0; i < mysize; i++){
        data[i] = rand() % 50;
    }

    MPI_Barrier(MPI_COMM_WORLD);
    double startTime = MPI_Wtime();

    calc_max5(data, mysize, max_5);

    if (rank == 0){

        for(int i = 0; i < 5; i++){
            max5_all[i] = max_5[i];
        }

        for(source = 1; source < numproc; source++){
            MPI_Recv(max_5, 5, MPI_INT, source, 0, MPI_COMM_WORLD, &status);
            for(int i = 0; i < 5; i++){
                max5_all[source * 5 + i] = max_5[i];
            }
        }
        calc_max5(max5_all, 5 * numproc, max_5);

        delete[] max5_all;
    } else {
        MPI_Send(max_5, 5, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }

    MPI_Barrier(MPI_COMM_WORLD);
    double endTime = MPI_Wtime();

    if(rank == 0){
        printf("I primi 5 massimi sono: ");
        for(int i = 0; i < 5; i++){
            printf("%d ", max_5[i]);
        }
        printf("\nElapsed time: %f milliseconds\n", 1000 * (endTime - startTime));
    }

    delete[] data;
    MPI_Finalize();
    return 0;
}
