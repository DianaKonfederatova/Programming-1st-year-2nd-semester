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

bool poor_student_search(Stud* student){
    for (int i = 0; i < 4; i++){
        if(student -> grades[i] < 3){
            return true;
        }
    }
    return false;
}

void deleteStudent(Stud*& head1, Stud* curr){
    if (curr == nullptr){
        return;
    }

    if(curr->prev == nullptr){
        head1 = curr -> next;
    }else{
        curr -> prev -> next = curr -> next;
    }

    if (curr -> next != nullptr){
        curr -> next -> prev = curr -> prev;

    }

    delete curr;
}

void deletePoorStudent(Stud*& head1){
    if (head1 == nullptr){
        return;
    }

    Stud* curr = head1;

    while (curr != nullptr){
        Stud* nextStud = curr -> next;

        if(poor_student_search(curr)){
            deleteStudent(head1, curr);
        }

        curr = nextStud;
    }
}

void printListDouble(Stud* head1){
    if(head1 == nullptr){
        std::cout << "Список пуст, нет студентов\n";
        return;
    }

    Stud* curr = head1;

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
    //1-ое задание
    std::cout << "\nЗАДАНИЕ №1\n";
    Student* head = nullptr;
    insertStudent(head, "Драгун", 5, 5, 5, 5);
    insertStudent(head, "Помогаева", 2, 2, 3, 2);
    insertStudent(head, "Бровченко", 3, 4, 5, 3);
    insertStudent(head, "Кулибяков", 4, 5, 5, 5);

    sort_by_surname(head);
    print_List(head);

    //2-ое задание
    std::cout << "\nЗАДАНИЕ №2\n";
    Stud* head1 = nullptr;
    addStudent(head1, "Бубкин", 5, 5, 5, 5);
    addStudent(head1, "Трубкин", 2, 2, 3, 2);
    addStudent(head1, "Валынкина", 3, 2, 2, 3);
    addStudent(head1, "Прохоровна", 5, 4, 5, 5);

    std::cout << "\n----------СПИСОК ДО----------\n";
    printListDouble(head1);
    deletePoorStudent(head1);
    std::cout << "\n----------СПИСОК ПОСЛЕ----------\n";
    printListDouble(head1);
}