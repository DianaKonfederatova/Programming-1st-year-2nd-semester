#include <iostream>
#include <cstring>

struct Node {
    char word[100];
    Node* next = nullptr;
}




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
    std::cout << "====ТЕКСТ ФАЙЛА====\n" << "\n";
    while(fgets(line, 300, f) != NULL){
        std::cout << line;
    }
    std::cout << "===================\n";

    std::cout << "\n";
    rewind(f); 
    std::cout << "===РАЗБОР СТРОК ТЕКСТА НА СЛОВА===\n";

    while(fgets(line, 300, f) != NULL){
        std::cout << "\n";
        std::cout << "Исходная строка: "<< line << "\n";

        char* word = strtok(line, " \t\n");
        while (word != NULL){
            std::cout << word <<"\n";
            word = strtok(NULL, " \t\n");
        }
    }
    std::cout << "==================================\n";

    Node* head = nullptr;
    
    fclose(f);
    return 0;
}