#include <stdio.h>
#include <stdlib.h>
#define ROWS 5
#define COLS 10

void countAboveAverage(int matrix[ROWS][COLS]) {
    int count[COLS] = {0};
    double averages[COLS] = {0};
    for (int j = 0; j < COLS; j++) {
        double sum = 0;
        for (int i = 0; i < ROWS; i++) {
            sum += matrix[i][j];
        }
        averages[j] = sum / ROWS;
    }
    
    for (int j = 0; j < COLS; j++) {
        for (int i = 0; i < ROWS; i++) {
            if (matrix[i][j] > averages[j]) {
                count[j]++;
            }
        }
    }
    printf("Кількість елементів у кожному стовпці, більших за середнє арифметичне:\n");
    for (int j = 0; j < COLS; j++) {
        printf("Стовпець %d: %d\n", j + 1, count[j]);
    }
}

int main() {
    system("chcp 65001");
    int matrix[ROWS][COLS] = {
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
        {10, 9, 8, 7, 6, 5, 4, 3, 2, 1},
        {2, 3, 4, 5, 6, 7, 8, 9, 10, 1},
        {5, 6, 7, 8, 2, 10, 1, 2, 3, 4},
        {7, 8, 9, 10, 1, 2, 3, 4, 5, 6}
    };
    countAboveAverage(matrix);
    return 0;
}