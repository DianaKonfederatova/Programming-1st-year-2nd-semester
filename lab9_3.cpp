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
        sum += static_cast<int>(c);
    }

    int ostatok = sum % 17;

    return ostatok;
}

void addStudent(const Student& stud){
    int index = hash_function(stud.surname);

    if(!table[index].empty()){
        collisions[index]++;
    }

    table[index].push_back(stud);
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
    
}