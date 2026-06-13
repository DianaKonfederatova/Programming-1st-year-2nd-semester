#include <iostream>
#include <cstdio>
#include <limits> 

struct Student {
    char fio[60];
    int grades[4];
    double scholarship;
};

void createFile(){
    std::cout << "Создание файла: \n";

    FILE *fp = fopen("students.dat", "wb");

    if(fp == NULL){
        std::cout << "Ошибка создания файла!\n";
        return;
    }

    for(int i = 0; i<5; i++){
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        Student st;

        std::cout << "Введите ФИО студента:\n";
        std::cin.getline(st.fio, sizeof(st.fio));
        std::cout << "Введите 4 оценки за сессию через пробел:\n";
        for (int j = 0; j < 4; j++) {
            std::cin >> st.grades[j];
        }
        std::cout << "Введите размер степендии студента:\n";
        std::cin >> st.scholarship;

        fwrite(&st, sizeof(Student), 1, fp);
    }

    fclose(fp);
}

int main(){

    int choice;

    do{
        std::cout << "\n==================== МЕНЮ ====================\n";
        std::cout << "Введите пункт: \n";
        std::cout << "1. Создать файл\n";
        std::cout << "2. Просмотреть файл\n";
        std::cout << "3. Изменить оценки студента\n";
        std::cout << "4. Удалить записи о студентах с неуспеваемостью\n";
        std::cout << "5. Назаначить степендии по успеваемости\n";
        std::cout << "0. Выйти из меню\n";
        std::cout << "\n==============================================\n";
        
        std::cin >> choice;

        if(choice < 0 || choice > 5){
            std::cout << "Неправильный выбор. Введите число от 0 до 5\n";
            continue;
        }

        
        switch (choice){
            case 1:
                createFile();
                break;
            case 2;

            case 3;

            case 4;

            case 5;

            case 0;
        }

    } while(choice != 0);

}