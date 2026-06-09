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

void printList_Decrease(Student* head){

    if(head == nullptr){
        return;
    }

    printList_Decrease(head->right);

    std::cout << head -> surname << " " << "оценки: "<<
    head -> grades[0] << " " << head -> grades[1]<< " "  << 
    head -> grades[2] << " " << head -> grades[3]<< "\n";
    

    printList_Decrease(head -> left);
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

Student* search(Student* root, std::string target){

    if(root == nullptr){
        return nullptr;
    }

    Student* curr = root;

    while(curr != nullptr){

        if(curr -> surname == target){
            return curr;

        }else if(curr -> surname > target){
            curr = curr -> left;
        }else{
            curr = curr -> right;
        }
    }

    return nullptr;
    
}

void free_tree(Student*& head){
    if(head == nullptr){
        return;
    }

    free_tree(head -> left);
    free_tree(head -> right);

    delete head;
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

    std::cout << "--------СТУДЕНТЫ ПО УБЫВАНИЮ--------\n";
    printList_Decrease(head);
    std::cout << "---------------------------------------\n";

    Student* found = search(head, "Бубкин");

    if(found != nullptr){
        std::cout << "Студент найден: \n" << found -> surname << "\n"; 
    }else{
        std::cout << "Студент не найден\n"; 
    }

    Student* notfound = search(head, "Барабашкин");

    if(notfound != nullptr){
        std::cout << "Студент найден: \n" << notfound -> surname << "\n"; 
    }else{
        std::cout << "Студент не найден\n"; 
    }

    free_tree(head);
    head = nullptr;
    
    return 0;
}