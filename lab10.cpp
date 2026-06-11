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

    f = fopen("file1.txt", "r");

    if(f == NULL){
        std::cout << "Ошибка открытия файла!\n";
        return 1;
    }

    char line[300];
    std::cout << "Текст файла:\n" << "\n";
    while(fgets(line, 300, f) != NULL){
        std::cout << line;
    }

    fclose(f);
    return 0;
}