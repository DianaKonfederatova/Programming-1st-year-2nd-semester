#include <stdio.h>
#define N 5

void new_massive(int *massive, int n){
    int min_first = massive[0];
    int index_first = 0;
    

    for(int i = 1; i<n; i++){

        if(min_first>massive[i]){
            min_first = massive[i];
            index_first = i;
        }
    }

    int min_second;
    int index_second;

    if (index_first == 0) {
        min_second = massive[1];
        index_second = 1;
    } else {
        min_second = massive[0];
        index_second = 0;
    }

    for(int j = 0; j<n; j++){

        if(j == index_first) {
            continue; 
        }

        if(min_second>massive[j]){
            min_second = massive[j];
            index_second = j;
        }

    }

    if(index_first < index_second){
        for (int i = index_first + 1; i < index_second; i++) {
            massive[i] = 0;
        }
    }

    if(index_first > index_second){
        for (int i = index_second + 1; i < index_first; i++) {
            massive[i] = 0;
        }
    }

}

int main(){
    int massive[N] = {7, 1, 6, 6, 1};
    printf("Массив до обработки\n");
    for(int i = 0; i<N; i++){
        printf("%d ", massive[i]);
    }
    printf("\n");
    
    new_massive(massive, N);

    printf("Массив после обработки\n");
    for(int j = 0; j<N; j++){
        printf("%d ", massive[j]);
    }
    printf("\n");

}