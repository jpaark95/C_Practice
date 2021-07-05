#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_CHAR 80

int main() {
    char inp[MAX_CHAR];
    char tmp_cpy[MAX_CHAR];
    char* word;
    printf("Input: ");
    fgets(inp, MAX_CHAR, stdin);
    strcpy(tmp_cpy, inp);
    printf("\n");
    word = strtok(tmp_cpy, " \n");
    while (word != NULL){
        printf("word: %s\n", word);
        word = strtok(NULL, " \n");
    }
    
    return 0;
}