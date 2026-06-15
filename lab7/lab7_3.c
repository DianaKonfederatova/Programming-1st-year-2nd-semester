#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//сортировка в убывании
void sort_decrease(int arr[], int n){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if (arr[j] < arr[i]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

//перебор (поиск элемента)
void enumeration(int massive[], int size){
    printf("Поиск перебором:\n");
    int iterations = 0;
    int search = 3;
    int copy_search = 0;
    int cout = 0;
    int flag = 0;
    
    for (int i = 0; i<size; i++){
        iterations++; 
        if(search == massive[i]){
            flag = 1;
            copy_search = massive[i];
            cout+=1;
        }
    }

    if(flag==1){
        printf("Найден элемент %d, количество элемента %d в массиве = %d\n", copy_search, search, cout);
    }

    if(flag!=1){
        printf("Элемент не найден\n");
    }

    printf("Количество итераций перебора: %d\n\n", iterations);
}

//бинарный поиск
void binary_search(int massive[], int size){
    printf("Бинарный поиск:\n");
    int search = 5;
    int copy_search = 0;
    int flag = 0;
    int iterations = 0;

    int midle;
    int left = 0;
    int right = size - 1;
    

    while(left <= right){
        iterations++; 
        midle = left + (right - left) / 2;

        if (search == massive[midle]){
            flag = 1;
            copy_search = massive[midle];
            break;
        }
        
        if(search > massive[midle]){
            right = midle - 1;
        }
        else if(search < massive[midle]){ 
            left = midle + 1;
        }

    }

    if(flag==1){
        printf("Найден элемент %d\n", copy_search);
    }

    if(flag!=1){
        printf("Элемент не найден\n");
    }

    printf("Количество итераций бинарного поиска: %d\n\n", iterations);

}

int main(){
    srand(time(NULL));
    int n = 100;
    int N = 1000;
    int arr_100 [n]; 
    int arr_1000 [N];

    for (int i = 0; i < n; i++) {
        arr_100[i] = rand() % 20; 
    }

    for (int i = 0; i < N; i++) {
        arr_1000[i] = rand() % 20; 
    }

    printf("Исходный массив из 100 элементов:\n");
    for(int i = 0; i < n; i++){
        printf("%d ", arr_100[i]);
    }
    printf("\n");

    sort_decrease(arr_100, n);
    printf("Упорядоченный массив из 100 элементов:\n");
    for(int i = 0; i < n; i++){
        printf("%d ", arr_100[i]);
    }
    printf("\n");

    enumeration(arr_100, n);
    binary_search(arr_100, n);

    printf("Исходный массив из 1000 элементов:\n");
    for(int i = 0; i < N; i++){
        printf("%d ", arr_1000[i]);
    }
    printf("\n");

    sort_decrease(arr_1000, N);
    printf("Упорядоченный массив из 1000 элементов:\n");
    for(int i = 0; i < N; i++){
        printf("%d ", arr_1000[i]);
    }
    printf("\n");

    enumeration(arr_1000, N);
    binary_search(arr_1000, N);

    return 0;
}