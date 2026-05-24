#include <iostream>
#include <string>

struct Student {
    std::string surname;
    int grades[4];
    Student* next = nullptr; 
};

void add_student(Student*& head, std::string surname, 
    int gr1, int gr2, int gr3, int gr4){
        Student* newStudent = new Student;
        newStudent->surname = surname;
        newStudent->grades[0] = gr1;
        newStudent->grades[1] = gr2;
        newStudent->grades[2] = gr3;
        newStudent->grades[3] = gr4;
        newStudent->next = head;
        head = newStudent;
}

void print_students(Student* head){
   
    Student* temp = head;

    while(temp != nullptr){
       std::cout << temp -> surname << " ";
       
       for(int i = 0; i < 4; i++){
           std::cout << temp -> grades[i] << " ";
       }

       std::cout << "\n";
       temp = temp -> next;
    }

    
}

void sort_student(Student*& head){
    if(head == nullptr){
        return;
    }

    
}

int main(){

    Student* head = nullptr;
    
    add_student(head, "Драгун", 5, 5, 5, 5);
    add_student(head, "Белобрысов", 3, 2, 5, 5);
    add_student(head, "Кардамонов", 4, 5, 4, 5);
    add_student(head, "Лишаева", 5, 2, 2, 2);

    std::cout << "Список студентов:" << std::endl;
    print_students(head);

    return 0;
}