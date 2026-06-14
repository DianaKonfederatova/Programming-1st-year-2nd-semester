#include <stdio.h>
#include <time.h> 
#include <stdlib.h> 

void examination(int number[], int number_gamer[], int *bull, int *cow){
    int n = 4;
    *bull = 0;
    *cow = 0;

    for (int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){

            if(number[i] == number_gamer[j]){
                if (i == j){
                    (*bull)++;
                }else{
                    (*cow)++;
                }
                break;
            }
        }
    }
}

void game(){
    printf("\n|=|=|=|=|=|=|=|=| ИГРА НАЧАЛАСЬ |=|=|=|=|=|=|=|=|\n");
    printf("\n Приветствую тебя в игре! Правила просты.\n");
    printf("Я загадываю тебе число из 4-ех неповторяющихся цифр.\n");
    printf("Твоя задача - угадать число. Не бойся!) Подсказки будут.\n");
    printf("Если ты угадаешь некоторые цифры из числа, то я скажу,\n");
    printf("сколько цифр ты угадал и стоят ли они на своих местах.\n");
    printf("\nЗагадываю число...\n");
    
    int number[4];
    int numbers_used[10] = {0};
    int uniqueness_counter = 0;
    int bull = 0;
    int cow = 0;
    int the_end = 0;

    while (uniqueness_counter < 4){
        int numb = rand() % 10;

        if(numbers_used[numb] == 0){
            number[uniqueness_counter] = numb;
            numbers_used[numb] = 1;
            uniqueness_counter++;
        }
    }

    printf("Загадал! приступаем к игре:\n");

    while(the_end != 1){
        printf("Введи 4 цифры слитно:\n");
        
        char input[10];
        scanf("%4s", input);

        int number_gamer[4];
        
        for (int i = 0; i < 4; i++){
            number_gamer[i] = input[i] - '0';
        }

        examination(number, number_gamer, &bull, &cow);
        
        if(bull == 4){
            printf("Поздравляю! Ты угадал число!\n");
            printf("Игра окончена!\n");
            the_end = 1;
        }else{
            printf("-------------------------------------------------\n");
            printf("\nПодсказка:\n");
            printf("Угаданы и на своих местах: %d %s\n", bull, (bull == 1) ? "цифра" : ((bull >= 2 && bull <= 4) ? "цифры" : "цифр"));
            printf("Угаданы, но не на своих местах: %d %s\n", cow, (cow == 1) ? "цифра" : ((cow >= 2 && cow <= 4) ? "цифры" : "цифр"));
            printf("-------------------------------------------------\n");
            printf("Ты пока не угадал число :(\n");
            printf("Попробуй еще раз! :)\n");
            printf("\n");
        }
    }
}

int main(){
    srand(time(NULL));
    int choice;

    do{
        printf("\n|=|=|=|=|=|=|=|=| БЫКИ И КОРОВЫ |=|=|=|=|=|=|=|=|\n");
        printf("Здравствуй, дорогой друг! Хочешь ли ты сыграть?\n");
        printf("Введи пункт ответа:\n");
        printf("1. Да\n");
        printf("2. Нет\n");
        printf("Твой ответ: ");

        if (scanf("%d", &choice) != 1) {
            printf("\n!!!Ошибка: нужно ввести число 1 или 2!!!\n");
            while(getchar() != '\n'); 
            continue;
        }

        printf("|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|\n");

        switch(choice){
            case 1:
                game();
                break;
            case 2:
                printf("До скорой встречи! Жаль не поиграли...\n");
                break;
            default:
                printf("Неверный выбор. Введите 1 или 2.\n");
        }

    }while(choice != 2);
    
    return 0;
}