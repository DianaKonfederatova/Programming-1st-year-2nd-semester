#include <iostream>
#include "sort.h"
#include <ctime>

template <typename T>
double timer(void (*tip_sort)(T*, int), T* a, int n) {
    clock_t start = clock();
    tip_sort(a, n);
    clock_t end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC;
}

int main(){
    const int n = 50000;
    int massive_int[n];

    for (int i = 0; i < n; i++) {
        massive_int[i] = n - i;
    }

    double time_int = timer(sort, massive_int, n);
    std::cout << "Время сортировки int:   " << time_int << " сек.\n";

    float massive_float[n];
    for (int i = 0; i < n; i++) {
        massive_float[i] = (float)(n - i); // Заполняем в обратном порядке
    }

    double time_float = timer(sort, massive_float, n);
    std::cout << "Время сортировки float: " << time_float << " сек.\n";

    return 0;
}