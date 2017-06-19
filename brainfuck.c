#include <stdio.h>
#include <stdlib.h>
#include "brainfuck.h"

int main(int argc, char **argv) {
    uint8_t *ptr = NULL;
    ptr = (uint8_t *) calloc(30000, sizeof(char));

    FILE *file = NULL;
    char source[1024];
    size_t read;
    file = fopen("source.b", "r");
    if(file) {
        while((read = fread(source, 1, sizeof(source), file)) > 0) {
            fwrite(source, 1, read, stdout);
        }
        if(ferror(file)) {
            fprintf(stderr, "file error\n");
            exit(1);
        }
        fclose(file);
    }

    if(ptr == NULL) {
        fprintf(stderr, "calloc failed\n");
        exit(1);
    }

    int x = 0;
    while(source[x] != '\n') {
        printf("%c", source[x]);
        x++;
    }

    return 0;
}

void run(uint8_t* ptr, char* source) {
    printf("test: %u\n", ptr[2]);
}
