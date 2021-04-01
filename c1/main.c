#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


double** allocate_matrix(int n, double **A) {
    A = (double**) malloc(n * sizeof(double*));
    A[0] = (double*) malloc(n * n * sizeof(double));
    for (int i=1; i<n; i++) {
        A[i] = A[0] + i*n;
    }
    return A;
}

void gen(int n, double*** A, double*** B, double*** C) {

    *A = allocate_matrix(n, *A);
    *B = allocate_matrix(n, *B);
    *C = allocate_matrix(n, *C);

    double offset = (double) RAND_MAX/2;
    double M = (double) 2*sqrt(pow(10,16)/n);
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            (*A)[i][j] = ((double) rand() / (double) RAND_MAX)*M - offset;
            (*B)[i][j] = ((double) rand() / (double) RAND_MAX)*M - offset;
            /*(*C)[i][j] = 0;*/
        }
    }
}

void mult(int n, double A[][n], double B[][n], double C[][n]) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            double cij = 0;
            for (int k=0; k<n; k++) {
                cij += A[i][k] + B[k][j];
            }
            C[i][j] = cij;
        }
    }
}

double average(int K, double record_time[]) {
    double sum = 0;
    for (int i=0; i<K; i++) {
        sum += record_time[i];
    }
    return sum/K;
}

int main(int argc, char *argv[]) {
   int K = 10; // Amount of repetition of tests
   int N = 400; // Matrix size

   if (argc>1) {
       N = strtol(argv[1], NULL, 10);
   }
   if (argc > 2) {
       K = strtol(argv[2], NULL, 10);
   }

   double** A, **B, **C;
   gen(N, &A, &B, &C);

   double time_record[K];
   for (int i=0; i<K; i++) {
       clock_t start_time = clock(); 
       mult(N, (double (*)[N]) (*A), (double (*)[N]) (*B), (double (*)[N]) (*C));
       clock_t finish_time = clock();

       double duration_time = (double)(finish_time - start_time) / CLOCKS_PER_SEC;
       time_record[i] = duration_time;
       printf("Loop %d: %f seconds\n", i, duration_time);
   }

   double average_time = average(K, time_record);
   printf("Average time: %f seconds\n", average_time);

   return 0;
}
