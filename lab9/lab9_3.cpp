#include <iostream>
#include <string>
#include <list>
#include <vector>

struct Student {
    std::string surname;
    int grades[4]; 
};

std::vector<std::list<Student>> M(17);
int collisions[17] = {0};

int hash_function(const std::string& surname){
    int sum = 0;

    for(char c : surname){
        sum += static_cast<unsigned char>(c);
    }

    int ostatok = sum % 17;

    return ostatok;
}

void addStudent(const Student& stud){
    int index = hash_function(stud.surname);

    if(!M[index].empty()){
        collisions[index]++;
    }

    M[index].push_back(stud);
}

void findStudent(const std::string& target_surname) {
    int index = hash_function(target_surname);
    bool found = false;
    
    for (const auto& stud : M[index]) {
        if (stud.surname == target_surname) {
            std::cout << "Студент найден в ячейке " << index << "\n";
            std::cout << "Фамилия: " << stud.surname << "\n";
            std::cout << "Оценки: ";
            for (int j = 0; j < 4; j++) {
                std::cout << stud.grades[j] << " ";
            }
            std::cout << "\n\n";
            found = true;
            break;
        }
    }
    
    if (!found) {
        std::cout << "Студент с фамилией '" << target_surname << "' не найден.\n\n";
    }
}

int main(){

    Student students[12] = {
        {"Иванов", {5, 4, 5, 4}},
        {"Котельников", {3, 3, 4, 5}},
        {"Парышев", {5, 5, 5, 5}},
        {"Смирнов", {4, 4, 4, 4}},
        {"Кузнецов", {5, 3, 4, 4}},
        {"Попов", {3, 4, 3, 3}},
        {"Васильев", {5, 5, 4, 5}},
        {"Фокин", {4, 5, 5, 4}},
        {"Михайлов", {3, 3, 3, 4}},
        {"Василькин", {5, 4, 4, 5}},
        {"Федотов", {4, 4, 5, 5}},
        {"Морозов", {5, 5, 5, 5}}
    };

    for (int i = 0; i < 12; i++) {
        addStudent(students[i]);
    }

    for(int i = 0; i < 17; i++){
        std::cout << "Номер ячейки: " << i+1 << "\n";
        std::cout << "Количество коллизий: " << collisions[i] << "\n";
        
        for(auto stud : M[i]){
            std::cout << stud.surname << " ";
        }

        std::cout << "\n\n";
    }

    int col_sum = 0;
    
    for(int i = 0; i < 17; i++){
        col_sum += collisions[i];  
    }

    double middle_col = static_cast<double>(col_sum)/ 17; 
    std::cout << "Среднее количество коллизий: " << middle_col << "\n\n"; 

    std::cout << "===== ПОИСК СТУДЕНТОВ =====\n";
    findStudent("Смирнов");
    findStudent("Шреков");
    findStudent("Василькин");

    std::cout << "===========================\n";

    return 0;
}