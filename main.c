#include <stdio.h>
#include <time.h>
#include <stdlib.h>


char *getword(FILE *wordlist,int linecount) {
    int r = rand() % linecount;
    char ch;
    int line_i;
    while(!feof(wordlist)&&line_i<linecount) {
        ch = fgetc(wordlist);
        if(ch=='\n') {
            line_i++;
        }
    }
    
}

int countlines(FILE *wordlist) {
    int lines = 0;
    char ch;
    while(!feof(wordlist)) {
        ch = fgetc(wordlist);
        if(ch == '\n') {
            lines++;
        }
    }
    fseek(wordlist,0,SEEK_SET);
    return lines;
}
int moveto(int n, FILE *file) {
    int 
}
int main() {
    srand(time(NULL));
    FILE *wordlist = fopen("wordlist.txt","r");
    int linecount = countlines(wordlist);
    getword(wordlist,linecount);
    return 0;
}