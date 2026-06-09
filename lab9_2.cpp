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

void printList_Ascending(Student* head){
    
    if (head == nullptr){
        return;
    }

    printList_Ascending(head -> left);
    std::cout << head -> surname << " " << "оценки: "<<
    head -> grades[0] << " " << head -> grades[1]<< " "  << 
    head -> grades[2] << " " << head -> grades[3]<< "\n";
    

    printList_Ascending(head -> right);

}

int main(){
    Student* head = nullptr;
    addStudent(head, "Бубкин", 5, 5, 5, 5);
    addStudent(head, "Трубкин", 2, 2, 3, 2);
    addStudent(head, "Валынкина", 3, 2, 2, 3);
    addStudent(head, "Прохоровна", 5, 4, 5, 5);

    std::cout << "--------СТУДЕНТЫ ПО ВОЗРАСТАНИЮ--------\n";
    printList_Ascending(head);
    std::cout << "---------------------------------------\n";

}