#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "header.h"
#define MAX_LENGTH 1000 // Максимальная длина строки

// char* process_string(char* line);

int main() {
    setlocale(LC_ALL, "Rus");
    FILE *input_file, *output_file;
    char input_filename[] = "input.txt"; // Имя входного файла
    char output_filename[] = "output.txt"; // Имя выходного файла
    char line[MAX_LENGTH]; // Строка для хранения данных из файла
    int line_len = 0;
    
    // Открываем входной файл
    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("Ошибка открытия файла %sn", input_filename);
        return 1;
    }

    // Читаем строку из файла
    fgets(line, MAX_LENGTH, input_file);

    // Закрываем входной файл
    fclose(input_file);
    line_len = strlen(line);
    // Обрабатываем строку

    char *new_line = (char*) malloc(line_len * sizeof(char));
    for(int k = 0; k < strlen(new_line); k ++){
        new_line[k] = ' ';
    }
    // new_line[strlen(new_line) - 1] = '\0';

    new_line = process_string(line);

    // Открываем выходной файл
    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Ошибка открытия файла %sn", output_filename);
        return 1;
    }

    // Записываем измененную строку в выходной файл
    fprintf(output_file, "%s", new_line);

    // Закрываем выходной файл
    fclose(output_file);

    // Освобождаем память для новой строки
    free(new_line);

    return 0;
}