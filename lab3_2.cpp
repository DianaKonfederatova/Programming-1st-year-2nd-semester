#include <iostream>
#include <random>

int main(){
    int n;
    std::cout << "Введите количество элементов массива: ";
    std::cin >> n;
    double* a = new double[n];//под элементы
    double** b = new double*[n];//под адреса

    std::random_device rd;//берет рандомые числа
    std::mt19937 gen(rd());//перемешивает и выдает последовательность чисел
    std::uniform_real_distribution<double> dist(0.0, 100.0);//диапозон рандомных чисел

    for (int i = 0; i < n; i++){
        a[i] = dist(gen);
    }


    for (int i = 0; i < n; i++){
        b[i] = &a[i];
    }

    for(int i = 0; i < n - 1; i++){

        int min_index = i;

        for (int j = i+1; j < n; j++){
            if (*b[min_index] > *b[j]){
                min_index = j;
            }
            
        }

        double* temp = b[i];
        b[i] = b[min_index];
        b[min_index] = temp;
        
    }
    
    std::cout << "Исходный массив:" << std::endl;
    for (int i = 0; i < n; i++){
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Отсортированный массив:" << std::endl;
    for (int i = 0; i < n; i++){
        std::cout << *b[i] << " ";
    }
    std::cout << std::endl;

    delete[] a;
    delete[] b;

}