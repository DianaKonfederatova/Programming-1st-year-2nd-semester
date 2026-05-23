#include <stdio.h>
#include <stdlib.h>
#define SCHOOLS 4

typedef struct{
    int number;
    int cout_graduates;
    int cout_of_applicants;
} School;

int main(){

    School schools[SCHOOLS] = {
        {120, 100, 23},
        {180, 50, 10},
        {124, 200, 100},
        {131, 20, 20}
    };

    int index[SCHOOLS];
    for (int i = 0; i < SCHOOLS; i++) {
        index[i] = i;
    }

    for (int i = 0; i < SCHOOLS - 1; i++) {
        for (int j = 0; j < SCHOOLS - i - 1; j++) {
            double procent_applicants_1 = ((double)schools[index[j]].cout_of_applicants / schools[index[j]].cout_graduates) * 100;
            double procent_applicants_2 = ((double)schools[index[j+1]].cout_of_applicants / schools[index[j+1]].cout_graduates) * 100;

            if(procent_applicants_1 > procent_applicants_2){
                int temp = index[j];
                index[j] = index[j+1];
                index[j+1] = temp;
            }
        }
    
    }
    
    printf("Результат сортировки: \n");
    for (int i = 0; i < SCHOOLS; i++){
        double procent_applicants= ((double)schools[index[i]].cout_of_applicants / schools[index[i]].cout_graduates) * 100;
        
        printf("Номер школы №%d, количество выпускников = %d, процент поступивших %.1f %%\n", schools[index[i]].number, schools[index[i]].cout_graduates, procent_applicants);
    }   
}