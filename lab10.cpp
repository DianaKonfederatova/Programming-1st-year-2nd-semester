#include <iostream>
#include <cstdio>
#include <cstring>

struct Node {
    char word[100];
    Node* next = nullptr;
};

int wordCount_List(Node* head){
    
    if(head == nullptr){
        return 0;
    }

    int count = 0;
    Node* curr = head;

    while(curr != nullptr){
        count++;
        curr = curr -> next;
    }

    return count;
}

void addWord_List(Node*& head, char* word){
    Node* newNode = new Node;
    strcpy(newNode->word, word);
    newNode -> next = nullptr;

    if(head == nullptr){
        head = newNode;
        return;
    }

    Node* curr = head;
    
    while(curr -> next != nullptr){
        curr = curr -> next;
    }

    curr -> next = newNode;
}




int main(){

    FILE* f = fopen("file1.txt", "w");

    if(f == NULL){
        std::cout << "Ошибка записи!\n";
        return 1;
    }

    fprintf(f, "А ниче тот факт, что...\n");
    fprintf(f, "Летом зима, весной осень\n");
    fprintf(f, "Курица - не птица, а собака - не волк\n");
    fprintf(f, "БУ бу бу\n");
    fprintf(f, "Уауауауауа дыээээ\n");

    fclose(f);

    f = fopen("file1.txt", "r");

    if(f == NULL){
        std::cout << "Ошибка открытия файла!\n";
        return 1;
    }

    char line[300];
    std::cout << "====ТЕКСТ ФАЙЛА====\n" << "\n";
    while(fgets(line, 300, f) != NULL){
        std::cout << line;
    }
    std::cout << "===================\n";

    std::cout << "\n";
    rewind(f);
    Node* head = nullptr; 
    
    int wordCount = 0;

    std::cout << "===РАЗБОР СТРОК ТЕКСТА НА СЛОВА===\n";

    while(fgets(line, 300, f) != NULL){
        std::cout << "\n";
        std::cout << "Исходная строка: "<< line << "\n";

        char* word = strtok(line, " \t\n.,-!?:;");
        while (word != NULL){
            std::cout << word <<"\n";
            wordCount++;
            addWord_List(head, word);
            word = strtok(NULL, " \t\n.,-!?:;");
        }
    }
    std::cout << "==================================\n";

    
    std::cout << "\n=== СЛОВА В СПИСКЕ ===\n";
    Node* curr = head;
    while(curr != nullptr) {
        std::cout << curr->word << "\n";
        curr = curr->next;
    }   
    std::cout << "======================\n";

    std::cout << "Количество слов в файле: "<< wordCount <<"\n";
    int count_in_List = wordCount_List(head);
    std::cout << "Количество слов в списке: "<< count_in_List <<"\n";


    fclose(f);
    return 0;
}