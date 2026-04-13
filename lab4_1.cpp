#include <iostream>
#include <cstdlib>
#include <ctime>

//g++ -std=c++11 -o lab4_1 lab4_1.cpp   -   команда компиляции

int main(){
    srand(time(nullptr));
    int m;
    int n = 5;
    std::cout << "Введите количество строк массива: ";
    std::cin >> m;
    
    int** matrix = new int*[m]; 
    for (int i = 0; i < m; i++) {
        matrix[i] = new int[n];          
    }

    for (int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            matrix[i][j] = rand() % 100;
        }
    }

    std::cout << "\nИсходная матрица B[" << m << "][" << n << "]:\n";
    for (int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            std::cout << matrix[i][j] << "\t"; 
        }
        std::cout << "\n";
    }

    int max_element = matrix[0][0];
    int max_m = 0;
    int max_n = 0;

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if(matrix[i][j] > max_element){
                max_element = matrix[i][j];
                max_m = i;
                max_n = j;
            }
        }
    }

    if (m <= 1 || n <= 1) {
        std::cout << "Невозможно создать матрицу C: слишком маленькие размеры.\n";
        for (int i = 0; i < m; i++) {
            delete[] matrix[i]; 
        }
        delete[] matrix;
        return 0; 
    }

    int** C = new int*[m-1];
    for (int i = 0; i < m-1; i++) {
        C[i] = new int[n-1];
    }

    int ci = 0;
    for (int i = 0; i < m; i++) {
        if (i == max_m) continue;
        int cj = 0;
        for (int j = 0; j < n; j++) {
            if (j == max_n) continue;
            C[ci][cj] = matrix[i][j];
            cj++;
        }
        ci++;
    }

    std::cout << "\nМатрица C[" << m-1 << "][" << n-1 << "]:\n";
    for (int i = 0; i < m-1; i++){
        for(int j = 0; j < n-1; j++){
            std::cout << C[i][j] << "\t"; 
        }
        std::cout << "\n";
    }

    for (int i = 0; i < m-1; i++) delete[] C[i];
    delete[] C;
    for (int i = 0; i < m; i++) delete[] matrix[i];
    delete[] matrix;

    return 0;
}