#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "readstr.h"

char wordlist[10][6];

char *chooseword() {
    int r = rand() % 10;
    char *word = malloc(6);
    word = wordlist[r];
    return word;
}

int play(char *word) {
    char* guess;
    while(1) {
        guess = read_string();
        if(strlen(guess)!=5) {
            fprintf(stderr, "Guess must be 5 Characters long");
            continue;
        }
    }
}

int main() {
    srand(time(NULL));
    strcpy(wordlist[0], "HOUSE");
    strcpy(wordlist[1], "KINGS");
    strcpy(wordlist[2],"PANDA");
    strcpy(wordlist[3],"CHINA");
    strcpy(wordlist[4],"BREAD");
    strcpy(wordlist[5],"HEATS");
    strcpy(wordlist[6],"FLOOR");
    strcpy(wordlist[7],"BEANS");
    strcpy(wordlist[8],"FLOUR");
    strcpy(wordlist[9],"EAGLE");
    printf("%s",chooseword());
    return 0;
}

