#include <iostream>
#include <string>

struct Student {
    std::string surname;
    int grades[4];
    Student* next = nullptr; 
};

void insertStudent(Student*& head, 
    std::string surname, int g1, int g2, int g3, int g4){
        Student* newStudent = new Student;
        newStudent -> surname = surname;
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

void print_List(Student* head){
    if(head == nullptr){
        std::cout << "Список пуст, нет студентов\n";
        return;
    }

    std::cout << "--------СПИСОК СТУДЕНТОВ--------\n";
    Student* curr = head;

    while(curr != nullptr){
        std::cout << curr -> surname << " оценки: ";
        
        for(int i = 0; i < 4; i++){
            std::cout << curr -> grades[i] << " ";
        }

        std::cout<<"\n";

        curr = curr -> next;

    }

    std::cout << "--------------------------------\n";
}


int main(){
    Student* head = nullptr;
    insertStudent(head, "Драгун", 5, 5, 5, 5);
    insertStudent(head, "Помогаева", 2, 2, 3, 2);
    insertStudent(head, "Бровченко", 3, 4, 5, 3);
    insertStudent(head, "Кулибяков", 4, 5, 5, 5);

    sort_by_surname(head);
    print_List(head);
}