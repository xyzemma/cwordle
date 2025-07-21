#ifndef READSTR_H_
#define READSTR_H_

#include <stdio.h>
#include <stdlib.h>

char* read_string() {
    int buf = sizeof(char)*8;
    int i = 0;
    char *string = (char *)malloc(buf);
    if (!string) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }

    while (1) {
        int c = getchar();
        if (c == EOF || c == '\n') {
            break;
        }
        if (i*sizeof(char) >= buf - 1) {
            buf += sizeof(char)*4;
            char *temp = (char *)realloc(string, buf);
            if (!temp) {
                free(string);
                fprintf(stderr, "Memory allocation failed\n");
                return NULL;
            }
            string = temp;
        }
        string[i++] = (char)c;
    }
    string[i] = '\0';
    return string;
}

#endif