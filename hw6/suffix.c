#include <stdio.h>
#include <string.h>
#include <ctype.h>

void print_instr(){
    printf("\nThis program takes two words and finds the longest common suffix.\n");
    printf("For example: the longest common suffix of 'cat' and 'mat' is 'at'.\n\n");

}

void make_lower_case(char* word1, char* word2){
    size_t len_word1 = strlen(word1);
    size_t len_word2 = strlen(word2);

    for (int x = 0; x < len_word1; x++){
        word1[x] = tolower(word1[x]);
    }

    for (int x = 0; x < len_word2; x++){
        word2[x] = tolower(word2[x]);
    }
    
}
char* find_common_suffix(char* word_a, char* word_b){
    size_t len_word_a = strlen(word_a);
    size_t len_word_b = strlen(word_b);
    int i = len_word_a - 1;
    int j = len_word_b - 1;

    while(word_a[i] == word_b[j]){
        i--;
        j--;
        
        if (i == j && i == -1) //bug fix where if words are same it decrements to negative values
            return (char*)&word_a[i+1];
    }
    printf("%d\n", i+1);
    return (char*)&word_a[i+1];;
}

int main() {
    char word1[30], word2[30];
    char* longest_suffix;
    print_instr();

    while(1){
        printf("Please enter two words (enter 'q q' to quit): ");
        scanf("%s %s", word1, word2);
        make_lower_case(word1, word2);

        if (strlen(word1) == 1 && (word1[0] == 'q' || word1[0] == 'Q') )
            break;

        longest_suffix = find_common_suffix(word1, word2);
        printf("The longest common suffix between '%s' and '%s' is '%s'\n\n", word1, word2, longest_suffix);
    }
    return 0;
} 