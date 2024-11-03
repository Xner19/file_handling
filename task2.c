#include <stdio.h>

int main() {
    FILE *file;
    int count = 0, words = 0, lines = 0;
    char c, ch, prev = ' ';

    file = fopen("task2test.txt", "r");
    if (file == NULL) {
        printf("Error! Could not open file.\n");
        return 1;
    }

    while ((ch = fgetc(file)) != EOF) {
        if ((ch != ' ' && ch != '\n') && (prev == ' ' || prev == '\n')) {
            words++;
        }
        if (ch == '\n') {
            lines++;
        }
        prev = ch;
    }

    fseek(file, 0, SEEK_SET);

    for (c = fgetc(file); c != EOF; c = fgetc(file)) {
        count++;
    }

    printf("The number of characters is %d\n", count);
    printf("The number of words is %d\n", words);
    printf("The number of lines is %d\n", lines);

    fclose(file);
    return 0;
}

