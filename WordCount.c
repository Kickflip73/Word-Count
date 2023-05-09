#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100

int countWords(char *line);
int countChars(char *line);

int main(int argc, char *argv[]) {
    char *fileName = "input.txt";
    char *option = "-c";
    int count = 0;

    if (argc >= 2) {
        option = argv[1];
    }

    if (argc >= 3) {
        fileName = argv[2];
    }

    FILE *file = fopen(fileName, "r");

    if (file == NULL) {
        printf("打卡文件出错 %s", fileName);
        return 1;
    }

    char line[MAX_WORD_LENGTH];

    while (fgets(line, sizeof(line), file)) {
        if (strcmp(option, "-c") == 0) {
            count += countChars(line);
        } else if (strcmp(option, "-w") == 0) {
            count += countWords(line);
        }
    }

    fclose(file);

    printf("%s数：%d\n", strcmp(option, "-c") == 0 ? "字符" : "单词", count);

    return 0;
}

int countWords(char *line) {
    int count = 0;
    char *token = strtok(line, " ,\n\r\t");

    while (token != NULL) {
        count++;
        token = strtok(NULL, " ,\n\r\t");
    }

    return count;
}

int countChars(char *line) {
    return strlen(line);
}
