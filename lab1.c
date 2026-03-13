#include <stdio.h>
#include <math.h>

void easter_year(int year){
    int a = year % 19;
    int b = year % 4;
    int c = year % 7;
    int d = ((19*a)+15)%30;
    int e = ((2*b)+(4*c)+(6*d)+6)%7;
    int f = d+e;

    if (f<=26){
        printf("Пасха будет праздноваться: %d апреля\n", f+4);
    }
    else{
        printf("Пасха будет праздноваться: %d мая\n", f-26);
    }
}

void raising_to_power(float base, int power){
    float y;
    while(power!=0){
        y = base * base;
        power--;
    }
    printf("y = %f\n", y);
}

//надо подумать над функцией, не доделана
void cosinus(int x){
    int p = 1;
    int z = 1;
    float cos_x;
    while (cos_x<0.0001){
        int numerator = pow(x, p);

        int factorial = 2 * z;
        int denuminator = 1;
        for (int i = 1; i<=factorial; i++){
            int denuminator *= i;     
        }

        float cos_x = numerator / denuminator;
        p++;
        z++; 
    }

    printf("cos(%d) = %f", x, cos_x);
    

}

int main(){

    int year;
    printf("Напишите год: \n");
    scanf("%d",&year);
    easter_year(year);
    
    float x;
    int n;
    printf("Введите вещественное число, которое будем возводить в степень: \n");
    scanf("%f", &x);
    printf("Введите целое положительно число для степени: \n");
    scanf("%d", &n);
    raising_to_power(x, n);
    
    int x1 = 1;
    int x2 = 10;
    int x3 = 100;
    cosinus(x1);
    cosinus(x2);
    cosinus(x3);
    


}