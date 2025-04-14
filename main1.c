#include <stdio.h>
 #include <stdlib.h>
 #define M 3
 #define N 4
 
 int areSumsUnique(int rowSums[], int colSums[], int rowCount, int colCount) {
     for (int i = 0; i < rowCount; i++) {
         for (int j = i + 1; j < rowCount; j++) {
             if (rowSums[i] == rowSums[j]) return 0;
         }
     }
     for (int i = 0; i < colCount; i++) {
         for (int j = i + 1; j < colCount; j++) {
             if (colSums[i] == colSums[j]) return 0;
         }
     }
     for (int i = 0; i < rowCount; i++) {
         for (int j = 0; j < colCount; j++) {
             if (rowSums[i] == colSums[j]) return 0;
         }
     }
     return 1;
 }
 
 int main() {
     system("chcp 65001");
     int matrix[M][N] = {
         {3, 6, 2, 1},
         {5, 2, 1, 4},
         {9, 12, 21, 10}
     };
     
     int rowSums[M] = {0};
     int colSums[N] = {0};
     
     for (int i = 0; i < M; i++) {
         for (int j = 0; j < N; j++) {
             rowSums[i] += matrix[i][j];
             colSums[j] += matrix[i][j];
         }
     }
     
     if (areSumsUnique(rowSums, colSums, M, N)) {
         printf("Суми всіх рядків і стовпців унікальні.\n");
     } else {
         printf("Є повторювані суми серед рядків або стовпців.\n");
     }
     
     return 0;
 }