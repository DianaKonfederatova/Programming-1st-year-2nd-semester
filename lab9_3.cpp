#include <iostream>
#include <string>
#include <list>
#include <vector>

std::vector<std::list<Student>> M(17);
int collisions[17] = {0};

struct Student {
    std::string surname;
    int grades[4]; 
};

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
    




}