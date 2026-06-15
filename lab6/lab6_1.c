#include <stdio.h>
#include <math.h>

int calculations(float a, float b, float c, float* p, float* s){
    if (a==0 || b==0 || c==0 || a+b <= c || a+c <= b || c+b <= a){
        return 0;
    }   
        
    *p = a+b+c;
    float semiper= *p/2;
    *s = sqrt(semiper*(semiper - a)*(semiper - b)*(semiper - c));
    
    return 1;    
}

int main(){
    float a = 2.0;
    float b = 3.0;
    float c = 4.0;

    float p;
    float s;

    int status = calculations(a, b ,c , &p, &s);
    
    if (status == 1){
        printf("Периметр треугольника = %.2f\n", p);
        printf("Площадь треугольника = %.2f\n", s);

    }
    else{
        printf("Такого треугольника не существует!\n");
    }

    return 0;
}