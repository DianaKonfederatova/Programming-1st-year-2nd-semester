#include <iostream>
#include <string>

int main(){

    FILE* f = fopen("file1.txt", "w");

    if(f == NULL){
        std::cout << "Ошибка записи!\n";
        return 1;
    }

    fprintf(f, "А ниче тот факт, что...\n");
    fprintf(f, "Летом зима, весной осень\n");
    fprintf(f, "Курица - не птица, а собака - не волк\n");
    fprintf(f, "БУ бу бу\n");
    fprintf(f, "Уауауауауа дыээээ\n");


    fclose(f);
    return 0;
}