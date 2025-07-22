#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "readstr.h"

char wordlist[10][6];

char *chooseword() {
    int r = rand() % 10;
    char *word = malloc(6);
    if(word==NULL) {
        printf("Error assigning memory");
        exit(1);
    }
    word = wordlist[r];
    return word;
}

int play(char *word) {
    char* guess;
    int guessnum = 0;
    while(1) {
        printf("Guess: ");
        guess = read_string();
        if(guess==NULL) {
            exit(1);
        }
        if(strlen(guess)!=5) {
            fprintf(stderr, "Guess must be 5 Characters long\n");
            continue;
        }
        if(strcmp(guess, word)==0) {
            fprintf(stdout,"You Won!\n");
            printf("Play again? (y|n) ");
            char* input = read_string();
            char* ycap = malloc(1);
            char* ylow = malloc(1);
            if(input==NULL||ycap==NULL||ylow==NULL) {
                exit(1);
            }
            *ycap = 'Y';
            *ylow = 'y';
            if(strcmp(input,ycap)==0 || strcmp(input, ylow)==0) {
                free(ycap);
                free(ylow);
                free(input);
                play(chooseword());
            } else {
                free(ycap);
                free(ylow);
                free(input);
                exit(0);
            }
        } else if(guessnum>=4) {
            printf("You Lost. The word was: %s\n",word);
            printf("Play again? (y|n) ");
            char* input = read_string();
            char* ycap = malloc(1);
            char* ylow = malloc(1);
            *ycap = 'Y';
            *ylow = 'y';
            if(input==NULL||ycap==NULL||ylow==NULL) {
                exit(1);
            }
            if(strcmp(input,ycap)==0 || strcmp(input, ylow)==0) {
                free(ycap);
                free(ylow);
                free(input);
                play(chooseword());
            } else {
                free(ycap);
                free(ylow);
                free(input);
                exit(0);
            }
        } else {
            guessnum++;
            char output[6];
            output[5] = '\0';
            for(int i=0;i<5;i++) {
                if(tolower(guess[i])==word[i]) {
                    output[i] = '=';
                } else if(strchr(word, guess[i])!=NULL) {
                    output[i] = '~';
                } else {
                    output[i] = 'x';
                }
            }
            free(guess);
            printf("%s\n",output);
            
        }
    }
}

int main() {
    srand(time(NULL));
    strcpy(wordlist[0], "house");
    strcpy(wordlist[1], "kings");
    strcpy(wordlist[2],"panda");
    strcpy(wordlist[3],"china");
    strcpy(wordlist[4],"bread");
    strcpy(wordlist[5],"heats");
    strcpy(wordlist[6],"floor");
    strcpy(wordlist[7],"beans");
    strcpy(wordlist[8],"flour");
    strcpy(wordlist[9],"eagle");
    play(chooseword());
    return 0;
}

