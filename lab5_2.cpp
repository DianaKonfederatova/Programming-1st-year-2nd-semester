#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
    int m = 9;
    int** matrix = new int*[m];

    for (int i = 0; i<m; i++){
        matrix[i] = new int[i+1];
    }

    for (int i = 0; i<m; i++){
        for (int j = 0; j<=i; j++){
            matrix[i][j] = (i+1) * (j+1);
        }
    }

    cout << "Таблица умножения\n" << endl;
    for (int i = 0; i < m; i++){
        for(int j = 0; j <= i; j++){
            cout << matrix[i][j] << "\t"; 
        }
        cout << "\n";
    }

    for(int i = 0; i<m; i++){
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}