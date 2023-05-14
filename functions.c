#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000 // Максимальная длина строки

char* process_string(char* line) {
    char *word, *new_word; // Указатели на текущее слово и новое слово
    int i = 0, j = 0, len = 0; // Индексы и длина текущего слова
    int line_len = 0; // Длина всей строки

    // Вычисляем длину строки
    line_len = strlen(line);

    // Выделяем память для новой строки
    char *new_line = (char*) malloc(line_len * sizeof(char));
    for(int k = 0; k < strlen(new_line); k ++){
        new_line[k] = ' ';
    }
    new_line[strlen(new_line) - 1] = '\0';

    // Обрабатываем слова в строке
    word = strtok(line, " ");
    int count = 0;
    while (word != NULL) {
        len = strlen(word);
        new_word = (char*) malloc((len)* sizeof(char));
        j = 0;
        // Копируем символы из текущего слова в новое слово
        if(word[len - 3] == 'i' && word[len - 2] == 'n' && word[len - 1] == 'g'){

            new_word = (char*) malloc((len - 1) * sizeof(char));
            for(i = 0; i < len - 3; i ++){
                new_word[i] = word[i];
            }
            new_word[len - 3] = 'e';
            new_word[len - 2] = 'd';
            new_word[len - 1] = '\0';

        }
        else{
            new_word = (char*) malloc(len * sizeof(char));
            strcpy(new_word, word);
        }
        count ++;
        printf("%d word %s new word %s \n", count, word, new_word);
        // Добавляем пробел и новое слово в новую строку
        strcat(new_line, " ");
        strcat(new_line, new_word);

        // Освобождаем память для нового слова
        free(new_word);

        // Получаем следующее слово
        word = strtok(NULL, " ");
    }
    //new_line[line_len - 1] = '\0';
    char *new_line2 = (char*) malloc((line_len - 6) * sizeof(char));
    strncpy(new_line2, new_line + 6, line_len); // делаем срез сроки (итоговой) т.к. в начале много мусора

    // Освобождаем память для новой строки
    free(new_line);
    return new_line2;
}
