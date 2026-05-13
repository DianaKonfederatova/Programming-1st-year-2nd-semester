#include <iostream>
#include <cmath>
#include <iomanip>


unsigned long long factorial(int num) {
    unsigned long long fact = 1;
    for (int i = 1; i <= num; ++i) {
        fact *= i;
    }
    return fact;
}

void cout_boys_and_girls(int n, int m, double& pd, double& pm){

    if(n<m){
        std::cout<<"Количество детей определенного пола не может превышать общее количество детей!"<<std::endl;
        return;
    }

    if (n<0 || m<0){
        std::cout << "Количество детей не может быть отрицательным числом!"<<std::endl;
        return;
    }

    float p = 0.45;
    float q = 1 - p;

    float c_n_m = factorial(n) / (factorial(m) * factorial(n - m));


    pd = c_n_m * std::pow(p, m) * std::pow(q, n - m);
    pm = c_n_m * std::pow(q, m) * std::pow(p, n - m);

}



int main(){
    int n = 10;
    int m = 2;

    double girls = 0;
    double boys = 0;

    cout_boys_and_girls(n, m, girls, boys);

    std::cout << std::fixed << std::setprecision(6);

    std::cout << "Вероятность " << m << " девочек из " << n << ": " << girls << std::endl;
    std::cout << "Вероятность " << m << " мальчиков из " << n << ": " << boys << std::endl;

    return 0;

}