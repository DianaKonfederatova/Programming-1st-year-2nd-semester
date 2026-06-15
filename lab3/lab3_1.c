#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int main(){
    srand(time(NULL));
    int n;
    printf("Введите размер массива:\n");
    scanf("%d", &n);
 
    int *b = (int*)malloc(n * sizeof(int));//начальный массив
    
    for (int i = 0; i < n; i++) {
        b[i] = (rand() % 101) - 50;
    }


    int positive = 0;
    for (int j = 0; j<n; j++){
        if (b[j]>=0){
            positive++;
        }
    }
    int *c = (int *)calloc(positive , sizeof(int));//для положительных чисел
    
    int index_c = 0;
    for(int z=0; z<=n; z++){
        if (b[z]>=0){
            c[index_c] = b[z];
            index_c++;
        }
    }

    int negative = 0;
    for (int i = 0; i<n; i++){
        if (b[i]<0){
            negative++;
        }
    }
    int *d = (int *)calloc(negative , sizeof(int));//для отрицательных

    int index_d = 0;
    for(int z=0; z<=n; z++){
        if (b[z]<0){
            d[index_d] = b[z];
            index_d++;
        }
    }

    printf("Исходный массив:\n");
    for(int i = 0; i<n; i++){
        printf("%d ", b[i]);
    }
    printf("\n");
    
    printf("Положительный массив:\n");
    for(int i = 0; i<positive; i++){
        printf("%d ", c[i]);
    }
    printf("\n");

    printf("Отрицательный массив:\n");
    for(int i = 0; i<negative; i++){
        printf("%d ", d[i]);
    }
    printf("\n");

    free(b);
    free(c);
    free(d);

}