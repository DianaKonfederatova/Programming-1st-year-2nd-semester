#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sort_decrease(int arr[], int n){
    for(int i = 0; i<n-1; i++){
        for(int j = 0; j<n; j++){
            if (arr[j] > arr[i]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
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
}