#include <iostream>
#include <string>

//структура узла для 1-ого задания
struct Student {
    std::string surname;
    int grades[4];
    Student* next = nullptr; 
};

struct Stud {
    std::string surname;
    int grades[4];
    Stud* next = nullptr; 
    Stud* prev = nullptr; 
};

//1-ое задние
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

//2-ое задание
void addStudent(Stud*& head1, std::string name, int g1, int g2, int g3, int g4){
    Stud* newStud = new Stud;
    newStud -> surname = name;
    newStud -> grades[0] = g1;
    newStud -> grades[1] = g2;
    newStud -> grades[2] = g3;
    newStud -> grades[3] = g4;
    newStud -> next = head1;
    newStud -> prev = nullptr;

    if(head1 != nullptr){
        head1 -> prev = newStud; 
    }

    head1 = newStud;
}


int main(){
    //1-ое задание
    Student* head = nullptr;
    insertStudent(head, "Драгун", 5, 5, 5, 5);
    insertStudent(head, "Помогаева", 2, 2, 3, 2);
    insertStudent(head, "Бровченко", 3, 4, 5, 3);
    insertStudent(head, "Кулибяков", 4, 5, 5, 5);

    sort_by_surname(head);
    print_List(head);

    //2-ое задание
    Stud* head1 = nullptr;
    addStudent(head1, "Бубкин", 5, 5, 5, 5);
    addStudent(head1, "Трубкин", 2, 2, 3, 2);
    addStudent(head1, "Валынкина", 3, 2, 2, 3);
    addStudent(head1, "Прохоровна", 5, 4, 5, 5);
}