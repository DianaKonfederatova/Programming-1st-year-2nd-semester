#include <iostream>
#include <cstdio>
#include <limits> 
#include <cstring> 

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

void viewFile(){
    std::cout << "Просмотр файла:\n";
    FILE *fp = fopen("students.dat", "rb");

    if(fp == NULL){
        std::cout << "Ошибка открытия файла для чтения!\n";
        return;
    }

    Student st;
    std::cout << "\n------ Список студентов ------\n";

    while(fread(&st, sizeof(Student), 1, fp) == 1){
        std::cout << "ФИО: " << st.fio << "\n";
        std::cout << "Оценки: " << st.grades[0] << " " << st.grades[1] << " " 
                  << st.grades[2] << " " << st.grades[3] << "\n";
        std::cout << "Стипендия: " << st.scholarship << " руб.\n";
        std::cout << "------------------------------\n";
    }

    fclose(fp);
}

void changeGrades(){
    std::cout << "Исправление оценок:\n";
    FILE *fp = fopen("students.dat", "r+b");

    if(fp == NULL){
        std::cout << "Ошибка открытия файла для перезаписи!\n";
        return;
    }

    char target_fio[60];
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очистка буфера!
    std::cout << "Введите ФИО студента для изменения оценок: ";
    std::cin.getline(target_fio, sizeof(target_fio));

    Student st;
    bool found = false; 

    while(fread(&st, sizeof(Student), 1, fp) == 1){
        
        if (strcmp(st.fio, target_fio) == 0) {
            found = true;
            std::cout << "Студент найден! Текущие оценки: " 
                      << st.grades[0] << " " << st.grades[1] << " " 
                      << st.grades[2] << " " << st.grades[3] << "\n";

        std::cout << "Введите 4 новые оценки через пробел: ";
            for (int j = 0; j < 4; j++) {
                std::cin >> st.grades[j];
            }

        fseek(fp, -sizeof(Student), SEEK_CUR);
        fwrite(&st, sizeof(Student), 1, fp);
        break;
        }
    }

    if (!found) {
        std::cout << "Студент с таким ФИО не найден в файле.\n";
    }

    fclose(fp);
}

void deleteStudent(){
    std::cout << "Избавление от студентов с неуспеваемостью:\n";
    FILE *fp = fopen("students.dat", "rb");
    FILE *out = fopen("t.dat", "wb");

    if(fp == NULL){
        std::cout << "Ошибка открытия файла!\n";
        return;
    }

    if(out == NULL){
        std::cout << "Ошибка создания файлв!\n";
        fclose(fp);
        return;
    }

    Student st;
    int deleted_count = 0;

    while(fread(&st, sizeof(Student), 1, fp) == 1){

        bool fail = false;
        for(int i = 0; i<4; i++){
            if(st.grades[i] == 2 || st.grades[i] == 1){
                fail = true;
                break;
            }
        }

        if(fail != true){
            fwrite(&st, sizeof(Student), 1, out);
        }else{
            deleted_count++;
            std::cout << "Удален студент: " << st.fio << "\n";
        }

    }

    fclose(fp);
    fclose(out);

    remove("students.dat");
    rename( "t.dat", "students.dat");
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
            case 2:
                viewFile();
                break;
            case 3:
                changeGrades();
                break;
            case 4:
                deleteStudent();
                break;
            case 5:
                std::cout << "Доработка пункта";
                break;
            case 0:
                break;
        }

    } while(choice != 0);

}