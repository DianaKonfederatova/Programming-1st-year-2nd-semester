#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    srand(time(nullptr));
    int* massive = new int[25];

    for(int i = 0; i<25; i++){
        massive[i] = rand()%100;
    }

    cout << "Исходный массив:\n";

    for(int i = 0; i<25; i++){
        cout << massive[i]<< " ";
    }

    int** matrix = new int*[5];

    for (int i = 0; i<5; i++){
        matrix[i] = &massive[i*5];
    }

    cout << "\n";
    cout << "Матрица 5x5:\n" << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    delete[] massive;
    delete[] matrix;

    return 0;
}