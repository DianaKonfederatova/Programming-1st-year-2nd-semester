#include <iostream>
#include <string>

struct Student {
    std::string surname;
    int grades[4];
    Student* next = nullptr; 
};

void insertStudent(Student*& head, 
    std::string surname, int g1, int g2, int g3, int g4){
        Sudent* newStudent = new Student;
        newStudent -> name = surname;
        newStudent -> grades[0] = g1;
        newStudent -> grades[1] = g2;
        newStudent -> grades[2] = g3;
        newStudent -> grades[3] = g4;
        newStudent -> next = head;
        head = newStudent;
}

void sort_by_surname(Student*& head){
    if(head == nullptr || head -> next == nullptr) return;
    
    int swap = 1;

    while(swap != 0){
        swap = 0;

        Student* prev = nullptr;
        Student* curr = head;

        while(curr != 0 && curr -> next !=nullptr){
            Student* second = curr -> next;

            if(curr -> surname > second -> surname){
                curr -> next = second -> next;
                second -> next = curr;

                if(prev == nullptr){
                    head = second;
                }else{
                    prev -> next = second;
                }

                swap = 1;

                prev = curr;
            }else{
                prev = curr;
                curr = curr -> next;
            }
        }
    }
}


int main(){
    Student* head = nullptr;
    insertStudent(head, "Драгун", 5, 5, 5, 5);
    insertStudent(head, "Помогаева", 2, 2, 3, 2);
    insertStudent(head, "Бровченко", 3, 4, 5, 3);
    insertStudent(head, "Кулибяков", 4, 5, 5, 5);

    
    
}