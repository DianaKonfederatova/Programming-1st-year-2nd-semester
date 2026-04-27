#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
    srand(time(nullptr));
    int m;
    int k;
    int rows;
    int last_rows_el;
    cout << "\nВведите количество элементов массива А: ";
    cin >> m;
    cout << "\nВведите количество элементов в строке матрицы B, которое будет меньше количества элементов массива А: ";
    cin >> k;

    if (k>m){
        cout << "\nНеверно введенное значение" << endl;
        return 1; 
    }

    int* A = new int[m];
    for (int i = 0; i<m; i++){
        A[i] = rand() % 100;
    }

    cout << "\nМассив А:\n";
    for (int i = 0; i<m; i++){
        cout << A[i] << "\t"; 
        cout << "\n";
    }

    int ostatok = m % k;
    if (ostatok == 0){
        rows = m/k;
        last_rows_el = k;
    }
    else{
        rows = (m/k)+1;
        last_rows_el = ostatok;
    }

    int** B = new int*[rows];
    for (int i = 0;i<rows;i++){
        if (i == rows - 1){
            B[i] = new int[last_rows_el];
        }
        else{
            B[i] = new int[k];
        }
    }

    int index = 0;

    for (int i = 0; i<rows; i++){
        int cur_row_el;
        if (i == rows-1){
            cur_row_el = last_rows_el;
        }
        else{
            cur_row_el = k;
        }

        for (int j = 0; j < cur_row_el; j++){
            if (index < m){
                B[i][j] = A[index];
                index++;
            } else {
                B[i][j] = 0;  
            }
        }
    }

    cout << "\nМатрица B:" << endl;
    for (int i = 0; i < rows; i++){
        int currentRowSize;
        if (i == rows - 1){
            currentRowSize = last_rows_el;
        } else {
            currentRowSize = k;
        }
        
        
        for (int j = 0; j < currentRowSize; j++){
            cout << B[i][j] << "\t";
        }
        cout << endl;
    }

    
    delete[] A; 
    
    for (int i = 0; i < rows; i++){
        delete[] B[i];  
    }
    delete[] B;  
    return 0;
}