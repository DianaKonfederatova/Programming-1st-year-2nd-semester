#include <iostream>
#include <string>

//структура узла для 1-ого задания
struct Student {
    std::string surname;
    int grades[4];
    Student* left = nullptr;
    Student* right = nullptr;  
};

void addStudent(Student*& head, std::string surname, int g1, int g2, int g3, int g4){
    Student* newStudent = new Student;
    newStudent -> surname = surname;
    newStudent -> grades[0] = g1;
    newStudent -> grades[1] = g2;
    newStudent -> grades[2] = g3;
    newStudent -> grades[3] = g4;
    Student* curr = head;
    
    if(head == nullptr){
        head = newStudent;
        return;
    }

    while(true){
        if(curr -> surname > newStudent -> surname){

            if(curr -> left == nullptr){
                curr -> left = newStudent;
                return;
            }else{
                curr = curr -> left;
            }

        }else if(curr -> surname < newStudent -> surname){

            if(curr -> right == nullptr){
                curr -> right = newStudent;
                return;
            }else{
                curr = curr -> right;
            }

        }else{
            std::cout << "Студент с такой фамилией уже есть!\n";
            delete newStudent;
            return;
        }
    }
}

int main(){
    Student* head = nullptr;

}