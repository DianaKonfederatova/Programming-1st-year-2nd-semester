#include "sort.h"
#include <iostream>

void sort(int* massive, int n){
    for(int i = 0; i<n-1; i++){
        int index = i;
        for(int j = i+1; j<n; j++){
            if (massive[j] < massive[index]){
                index = j;
            }
        }
        std::swap(massive[i], massive[index]);

    }
}

void sort(float* massive, int n){
    for(int i = 0; i<n-1; i++){
        int index = i;
        for(int j = i+1; j<n; j++){
            if (massive[j] < massive[index]){
                index = j;
            }
        }
        std::swap(massive[i], massive[index]);

    }

}