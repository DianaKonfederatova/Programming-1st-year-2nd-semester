#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sum_elements(int **matrix, int n){

    for(int i = 0; i<n; i++){

        int length = matrix[i][0];
        int sum = 0;

        for(int j = 1; j <= length; j++) {
            sum += matrix[i][j];
        }

        printf("Строка №%d, длина строки %d, сумма элементов строки = %d\n", i+1, length, sum);
    }
}


int main(){
    srand(time(NULL));
    int n = 4;//столбцы

    int **matrix = (int **)malloc(n * sizeof(int *));
    
    for(int i = 0; i<n; i++){

        int m = rand() % 9 +2;//строки

        matrix[i] = (int *)malloc((m+1)*sizeof(int));//+1 для длины

        matrix[i][0] = m;

        for(int j = 1; j <= m; j++) {
            matrix[i][j] = rand() % 10 + 1;
        }
    }

    printf("Исходный массив:\n");

    for(int i = 0; i<n; i++){

        int length = matrix[i][0];

        for(int j = 0; j <= length; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    sum_elements(matrix, n);

    for(int i = 0; i < n; i++) {
        free(matrix[i]); 
    }
    free(matrix);

    return 0;

}