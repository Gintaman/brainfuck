#include <stdio.h>
#include <stdlib.h>
#include "brainfuck.h"

int main(int argc, char **argv) {
    uint8_t *ptr = NULL;
    ptr = (uint8_t *) calloc(30000, sizeof(char));

    FILE *fp = NULL;
    char *line = NULL;

    fp = fopen("source.b", r);

    if(ptr == NULL) {
        fprintf(stderr, "calloc failed\n");
        exit(1);
    }

    run(ptr);

    return 0;
}

void run(uint8_t* ptr, char* source) {
    printf("test: %u\n", ptr[2]);
}
