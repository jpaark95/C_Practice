#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define SURNAME_LENGTH 16
#define FIRSTNAME_LENGTH 11
#define BUFFER_LENGTH 100

void read_names(FILE* infp, char** surnames, char** first_names, char* middle_initials, int num_names, char* buffer){

    char* surname_buf;
    char* first_name_buf;

    for(int i = 0; i < num_names; i++){
        fgets(buffer, BUFFER_LENGTH, infp);
        surname_buf = strtok(buffer, " ,.\n");
        first_name_buf = strtok(NULL, " ,.\n");

        strncpy(surnames[i], surname_buf, SURNAME_LENGTH);
        strncpy(first_names[i], first_name_buf, FIRSTNAME_LENGTH);
        middle_initials[i] = strtok(NULL, " ,.\n")[0];

        if (strlen(surnames[i]) == SURNAME_LENGTH)
            surnames[i][SURNAME_LENGTH-1] = '\0';
        if (strlen(first_names[i]) == FIRSTNAME_LENGTH)
            first_names[i][FIRSTNAME_LENGTH - 1] = '\0';       
    }
}

void sort(char** surnames, char** first_names, char* middle_initials, int num_names, char* buffer) {
    int min_index;
    char temp[SURNAME_LENGTH];
    char tmp;

    for(int i = 0; i < num_names - 1; i++){
        min_index = i;
        for(int j = i+1; j < num_names; j++){
            if(strcmp(surnames[min_index], surnames[j]) > 0){
                min_index = j;    
            }else if(strcmp(surnames[min_index], surnames[j]) == 0){
                if(strcmp(first_names[min_index], first_names[j]) > 0){
                    min_index = j;
                }
            }
        }

        strcpy(temp, surnames[min_index]);
        strcpy(surnames[min_index], surnames[i]);
        strcpy(surnames[i], temp);

        strcpy(temp, first_names[min_index]);
        strcpy(first_names[min_index], first_names[i]);
        strcpy(first_names[i], temp);
        
        tmp = middle_initials[min_index];
        middle_initials[min_index] = middle_initials[i];
        middle_initials[i] = tmp;

    }
}
void print_names(char** surnames, char** first_names, char* middle_initials, int num_names){
    for(int i = 0; i < num_names; i++){
        printf("%-15s %-10s %c\n", surnames[i], first_names[i], middle_initials[i]);
    }
}

void write_names(FILE* outfp, char** surnames, char** first_names, char* middle_initials, int num_names) {
    for(int i = 0; i < num_names; i++){
        fprintf(outfp, "%-15s %-10s %c\n", surnames[i], first_names[i], middle_initials[i]);
    }
}

void free_memory(char** surnames, char** first_names, char* middle_initials) {
    free(surnames);
    free(first_names);
    free(middle_initials);
}

int main(int argc, char* argv[]) {
    char** first_names;
    char** surnames;
    char* middle_initials;
    FILE* infp;
    FILE* outfp;
    char buffer[BUFFER_LENGTH];
    int num_names;

    infp = fopen(argv[1], "r");
    outfp = fopen(argv[2], "w");
    if (infp == NULL)
        printf("Error opening file\n");
    

    fgets(buffer, BUFFER_LENGTH, infp);
    if(buffer[strlen(buffer) - 1] == '\n')
        buffer[strlen(buffer) - 1] = '\0';
    num_names = atoi(buffer);

    surnames = (char**)malloc(sizeof(char*) * num_names);
    first_names = (char**)malloc(sizeof(char*) * num_names);
    middle_initials = (char*)malloc(sizeof(char) * num_names);
    
    for(int i = 0; i < num_names; i++){
        surnames[i] = (char*)malloc(sizeof(char) * SURNAME_LENGTH);
        first_names[i] = (char*)malloc(sizeof(char) * FIRSTNAME_LENGTH);
    }
    
    read_names(infp, surnames, first_names, middle_initials, num_names, buffer);
    sort(surnames, first_names, middle_initials, num_names, buffer);
    write_names(outfp, surnames, first_names, middle_initials, num_names);
    free_memory(surnames, first_names, middle_initials);
    fclose(infp);
    fclose(outfp);

    return 0;
}