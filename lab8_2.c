#include <stdio.h>

#define FACULTY 4
#define ROOM 8

typedef struct{
    int number;
    float s;
    int number_faculty;
    int number_of_people;

} Rooms;

typedef struct{
    char faculty[50]; 
} Directory;

int main(){
    
    Directory directory[FACULTY] = {
        {"Gryffindor"},
        {"Slytherin"},
        {"Ravenclaw"},
        {"Hufflepuff"}
    };

    Rooms rooms[ROOM] = {
        {1, 25.5, 0, 4},
        {2, 25.5, 0, 5},
        {3, 30.0, 1, 5},
        {4, 22.3, 1, 2},
        {5, 24.5, 2, 4},
        {6, 19.0, 2, 2},
        {7, 33.0, 3, 6 },
        {8, 20.0, 3, 3}
    };

    printf("БАЗА ДАННЫХ:\n");

    for(int i = 0; i<FACULTY; i++){
        printf("Факультет: %s\n", directory[i].faculty);
        

        for(int j = 0; j<ROOM; j++){
            if(rooms[j].number_faculty == i){
                printf("Комната №%d, площадь комнаты %.1f кв.м., количество студентов в комнате %d \n", rooms[j].number, 
                    rooms[j].s, rooms[j].number_of_people);    
            }
        }

        printf("\n");
    }

    printf("ДАННЫЕ О КОМНАТАХ\n");
    for(int i = 0; i<FACULTY; i++){
        printf("Факультет: %s\n", directory[i].faculty);

        float area = 0.0;
        int cout_students = 0;
        int cout_rooms = 0;

        for(int j = 0; j<ROOM; j++){
            if(rooms[j].number_faculty == i){
                area += rooms[j].s;
                cout_students += rooms[j].number_of_people;
                cout_rooms+=1;
            }
        }

        float middle_s = 0.0;
        if (cout_students > 0){
            middle_s = area / cout_students;
            printf("Количество комнат: %d, количество студентов: %d, средняя площадь на студента: %.2f кв.м\n",
                cout_rooms, cout_students, middle_s);
        } else {
            printf("В комнатах факультета никто не живет.\n");
        }
        
        printf("\n");
    }

    return 0;
}