#include <iostream>
#include <cstdlib>
#include <ctime>

int main(){
    srand(time(nullptr));
    int m;
    int n;
    std::cout << "Введите количество строк массива: ";
    std::cin >> m;
    std::cout << "Введите количество столбцов массива: ";
    std::cin >> n;
    
    int** A = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        A[i] = (int*)malloc(n * sizeof(int));
    }

    for (int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            A[i][j] = rand() % 100;
        }
    }

    std::cout << "\nИсходная матрица A[" << m << "][" << n << "]:\n";
    for (int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            std::cout << A[i][j] << "\t"; 
        }
        std::cout << "\n";
    }

    int** D = (int**)malloc((m + 1) * sizeof(int*));
    for (int i = 0; i < m + 1; i++) {
        D[i] = (int*)malloc((n + 1) * sizeof(int));
    }

    for (int i = 0; i < m + 1; i++) {
        for (int j = 0; j < n + 1; j++) {
            D[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            D[i][j] = A[i][j];
            D[i][n] += A[i][j];
            D[m][j] += A[i][j];
            D[m][n] += A[i][j];
        }
    }

    std::cout << "\nМатрица D с суммами:\n";
    for (int i = 0; i < m + 1; i++) {
        for (int j = 0; j < n + 1; j++) {
            std::cout << D[i][j] << "\t"; 
        }
        std::cout << "\n";
    }

    for (int i = 0; i < m; i++) free(A[i]);
    free(A);
    for (int i = 0; i < m + 1; i++) free(D[i]);
    free(D);

    return 0;
}