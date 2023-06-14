#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

// Функция для копирования файла
void copy_file(const char* input_filename, const char* output_filename) {
    // Открываем входной файл для чтения в двоичном режиме
    FILE* input_file = fopen(input_filename, "rb");
    // Открываем выходной файл для записи в двоичном режиме
    FILE* output_file = fopen(output_filename, "wb");
    
    // Проверяем успешность открытия файлов
    if (input_file == NULL || output_file == NULL) {
        printf("Ошибка открытия файлов.\n");
        return;
    }
    
    // Создаем буфер для чтения/записи данных
    char buffer[BUFFER_SIZE];
    size_t read_bytes; // Количество байт, прочитанных из файла
    
    // Читаем данные из входного файла и записываем их в выходной файл
    while ((read_bytes = fread(buffer, sizeof(char), BUFFER_SIZE, input_file)) > 0) {
        fwrite(buffer, sizeof(char), read_bytes, output_file);
    }
    
    // Закрываем файлы
    fclose(input_file);
    fclose(output_file);
    
    printf("Файл успешно скопирован.\n");
}

int main(int argc, char* argv[]) {
    // Проверяем наличие аргументов командной строки (имен входного и выходного файлов)
    if (argc < 3) {
        printf("Необходимо указать имена входного и выходного файлов.\n");
        return 1;
    }
    
    // Получаем имена входного и выходного файлов из аргументов командной строки
    char* input_filename = argv[1];
    char* output_filename = argv[2];
    
    // Вызываем функцию копирования файла
    copy_file(input_filename, output_filename);
    
    return 0;
}
