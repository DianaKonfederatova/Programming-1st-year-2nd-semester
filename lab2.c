#include <stdio.h>
#include <stdlib.h>

#define N 5
void output(int n, int arr[]); //прототип, чтобы компилятор уже зараннее знал функцию, не убирать!

void output(int n, int arr[]){
    if (n==0){
        return;
    }

   int term = arr[n-1];

   if (term<0){
    printf("%d\n", term);
   }

   output(n-1, arr);

   if (term>0){
    printf("%d\n", term);
   }
}

void clav(){
    int num;
    scanf("%d", &num);
    if(num==0){
        return;
    }

    clav();

    if (num>0){
        printf("%d\n", num);
    }

}


int main(){
    printf("1-ая задача:\n");
    printf("Вводите целые числа любые. Если захотите прекратить, нажмите 0:\n");
    clav();

    printf("2-ая задача:\n");
    int arr[N]={1, -1, 2 ,3, -5};
    output(N, arr);

    printf("3-тья задача");

}