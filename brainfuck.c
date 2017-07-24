#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "brainfuck.h"
#include <emscripten/emscripten.h>

#define END 0xa

int main(int argc, char **argv) {
    //tape pointer
    /*uint8_t *tp = NULL;
    tp = (uint8_t *) calloc(30000, sizeof(char));

    FILE *file = NULL;
    char source[1024] = {0};

    file = fopen("source.b", "r");
    if(file) {
        char c;
        int curr = 0;
        while((c = fgetc(file)) != EOF) {
            if(!isValid(c)) {
                fprintf(stderr, "Encountered invalid character ['%c'] in source, exiting.", c);
                return -1;
            }
            source[curr] = c;
            curr++;
        }
        if(ferror(file)) {
            fprintf(stderr, "File error\n");
            free(tp);
            exit(1);
        }
        fclose(file);
    }

    if(tp == NULL) {
        fprintf(stderr, "Calloc failed\n");
        free(tp);
        exit(1);
    } 
    //source pointer
	char *sp = &source[0];

	run(tp, sp);*/

    printf("hello, world\n");
    return 0;
}

#ifdef __cplusplus
extern "C" {
#endif
    void EMSCRIPTEN_KEEPALIVE run(uint8_t* tp, char* sp) {
        int sourcePointer = 0;
        int tapePointer = 0;
        char tok;

        while(sp[sourcePointer] != END) {
            tok = sp[sourcePointer];
            switch(tok) {
                case '>':
                    if(tapePointer < 30000) {
                        tapePointer++;
                    }
                    break;
                case '<':
                    if(tapePointer > 0) {
                        tapePointer--;
                    }
                    break;
                case '+':
                    tp[tapePointer] = tp[tapePointer] + 1;
                    break;
                case '-':
                    tp[tapePointer] = tp[tapePointer] - 1;
                    break;
                case '.':
                    putchar(tp[tapePointer]);
                    break;
                case ',':
                    break;
                case '[':
                    if(tp[tapePointer] == 0) {
                        int bal = 1;
                        while(bal > 0) {
                            sourcePointer++;
                            if(sp[sourcePointer] == '[') {
                                bal++;
                            }
                            else if(sp[sourcePointer] == ']') {
                                bal--;
                            }
                        }
                        sourcePointer++;
                    }
                    break;
                case ']':
                    if(tp[tapePointer] != 0) {
                        int bal = 1;
                        while(bal > 0) {
                            sourcePointer--;
                            if(sp[sourcePointer] == '[') {
                                bal--;
                            }
                            else if(sp[sourcePointer] == ']') {
                                bal++;
                            }
                        }
                    }
                    break;
                default:
                    fprintf(stderr, "Invalid token encountered\n");
                    break;
            }
            sourcePointer++;
        }
        printf("Program execution completed.\n");
    }
#ifdef __cplusplus
}
#endif

int isValid(char tok) {
    if(tok == 0xa) {
        fprintf(stdout, "Reached end of line character\n");
    }
    return tok == '>' || tok == '<' || tok == '+' || tok == '-' || tok == '.' || tok == ',' || tok == '[' || tok == ']';
}

//pointer to tape (memory cells), pointer to source code
//wasm compiled run function should just take in the array of memory cells and the source as an array of chars 
/*void run(uint8_t* tp, char* sp) {
    int sourcePointer = 0;
    int tapePointer = 0;
    char tok;

    while(sp[sourcePointer] != END) {
        tok = sp[sourcePointer];
        switch(tok) {
            case '>':
                if(tapePointer < 30000) {
                    tapePointer++;
                }
                break;
            case '<':
                if(tapePointer > 0) {
                    tapePointer--;
                }
                break;
            case '+':
                tp[tapePointer] = tp[tapePointer] + 1;
                break;
            case '-':
                tp[tapePointer] = tp[tapePointer] - 1;
                break;
            case '.':
				putchar(tp[tapePointer]);
                break;
            case ',':
                break;
            case '[':
                if(tp[tapePointer] == 0) {
                    int bal = 1;
                    while(bal > 0) {
                        sourcePointer++;
                        if(sp[sourcePointer] == '[') {
                            bal++;
                        }
                        else if(sp[sourcePointer] == ']') {
                            bal--;
                        }
                    }
                    sourcePointer++;
                }
                break;
            case ']':
                if(tp[tapePointer] != 0) {
                    int bal = 1;
                    while(bal > 0) {
                        sourcePointer--;
                        if(sp[sourcePointer] == '[') {
                            bal--;
                        }
                        else if(sp[sourcePointer] == ']') {
                            bal++;
                        }
                    }
                }
                break;
			default:
				fprintf(stderr, "Invalid token encountered\n");
				break;
        }
        sourcePointer++;
    }
    printf("Program execution completed.\n");
}*/
