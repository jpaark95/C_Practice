#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_CHAR 80

int main() {
    char inp[MAX_CHAR];
    char tmp_cpy[MAX_CHAR];
    char* word[40];
    int i = 0;
    printf("Input: ");
    fgets(inp, MAX_CHAR, stdin);
    strcpy(tmp_cpy, inp);

    word[0] = strtok(tmp_cpy, " \n");
    i++;

    while (1) { 
        word[i] = strtok(NULL, " \n");     
        if(word[i] == NULL)
            break;

        i++; 
    }

    i--;
    printf("Reversed: ");
    for(; i >= 0; i--){
        printf("%s ", word[i]);
    }

    printf("\n");
    return 0;
}