#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    printf("Введите конец диапазона решета Эратосфена: ");
    scanf("%d", &n);
    int *massive = (int *)calloc(n+1, sizeof(int));
    
    for (int i = 0; i <= n; i++){
        massive[i] = i;
    }
    
    for (int i = 2; i * i <= n; i++){
        if(massive[i]!=0){
            for(int j = i*i; j<=n; j+=i){
                    massive[j]=0;
            }
        }
    }

    for (int i = 2; i<=n; i++){
        if (massive[i]!=0){
            printf("%d ", massive[i]);
        }
    }

    free(massive);
}