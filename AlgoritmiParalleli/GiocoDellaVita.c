#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NCOLS 50
#define NROWS 30

#define v(r,c) ((r)*NCOLS+(c))

int* readM;
int* writeM;
int nsteps = 100;

void init() {
    int ii = NROWS / 2;
    int jj = NCOLS / 2;

    for (int i = 0; i < NROWS; i++)
        for (int j = 0; j < NCOLS; j++)
            readM[v(i, j)] = 0;

    readM[v(ii - 1, jj)] = 1;
    readM[v(ii, jj + 1)] = 1;
    readM[v(ii + 1, jj - 1)] = 1;
    readM[v(ii + 1, jj)] = 1;
    readM[v(ii + 1, jj + 1)] = 1;
}

void print(int step) {
    printf("---%d\n", step);
    for (int i = 0; i < NROWS; i++) {
        for (int j = 0; j < NCOLS; j++) {
            char ch = (readM[v(i, j)] == 1) ? '*' : '0';
            printf("%c ", ch);
        }
        printf("\n");
    }
}

void swap() {
    int* p = readM;
    readM = writeM;
    writeM = p;
}

void transFuncCell(int i, int j) {
    int cont = 0;
    for (int di = -1; di < 2; di++)
        for (int dj = -1; dj < 2; dj++)
            if ((di != 0 || dj != 0) && (i + di) >= 0 && (i + di) < NROWS &&
                (j + dj) >= 0 && (j + dj) < NCOLS && readM[v(i + di, j + dj)] == 1)
                cont++;

    if (readM[v(i, j)] == 1)
        writeM[v(i, j)] = (cont == 2 || cont == 3) ? 1 : 0;
    else
        writeM[v(i, j)] = (cont == 3) ? 1 : 0;
}

void transFunc() {
    for (int i = 0; i < NROWS; i++) {
        for (int j = 0; j < NCOLS; j++) {
            transFuncCell(i, j);
        }
    }
}

int main() {
    readM = (int*)malloc(NROWS * NCOLS * sizeof(int));
    writeM = (int*)malloc(NROWS * NCOLS * sizeof(int));

    if (readM == NULL || writeM == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    init();

    for (int s = 0; s < nsteps; s++) {
        print(s);
        sleep(1);
        transFunc();
        swap();
    }

    free(readM);
    free(writeM);

    return 0;
}
