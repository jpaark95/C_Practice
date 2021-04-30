#include <stdio.h>
#include <stdlib.h>

#define NUM_PRECINCTS 5
#define NUM_CANDIDATES 4
/*
    This function takes the text file containing the vote counts of the election
    and stores the values of the votes into the variable table
*/
void read_file(FILE* fp, int table[][NUM_CANDIDATES+1]){
    int total_votes = 0;
    for(int i = 0; i < NUM_PRECINCTS; i++){
        fscanf(fp, "%d%d%d%d%d", &table[i][0], &table[i][1], &table[i][2], &table[i][3], &table[i][4]);
    }

    for(int j = 1; j < NUM_CANDIDATES+1; j++){
        for(int i = 0; i < NUM_PRECINCTS; i++){
            total_votes += table[i][j];
        }
        table[NUM_CANDIDATES+1][j] = total_votes;
        total_votes = 0;
    }

    return;
}

/*
    This function sorts the candidates (columns) by total votes received
*/
void sort(int table[][NUM_CANDIDATES+1], char names[4]){ //TO_DO! TO_DO! TO_DO! TO_DO! TO_DO! 
    int sorted_ind[NUM_CANDIDATES+1] = {-99, 1, 2, 3, 4};
    int row = NUM_PRECINCTS; //row where totals are stored
    int max_ind;
    int tmp;
    char tmpc;
    int curr_max = 999999;

    for(int n = 1; n < NUM_CANDIDATES; n++){
        max_ind = n;
        for(int m = n+1; m < NUM_CANDIDATES; m++){
            if (table[row][m] > table[row][n])
                max_ind = m;
        }

        //swap total votes
        tmp = table[row][n];
        table[row][n] = table[row][max_ind];
        table[row][max_ind] = tmp;

        //swap candidate name
        tmpc = names[n-1];
        names[n-1] = names[max_ind-1];
        names[max_ind-1] = tmpc;

        //swap vote count columns
        for(int m = 0; m < NUM_PRECINCTS-1; m++){
            tmp = table[m][n];
            table[m][n] = table[m][max_ind];
            table[m][max_ind] = tmp;
        }
        
    }

    return;
}
/*
    This function displays the election information in a table
*/
void show_table(int table[][NUM_CANDIDATES+1], char names[4]){  
    printf("           Candidate  Candidate  Candidate  Candidate\n");
    printf("Precinct       %c          %c          %c          %c\n", names[0], names[1], names[2], names[3]);
    for(int i = 0 ; i < NUM_PRECINCTS; i++){
        printf("%4d%13d%11d%11d%11d\n", table[i][0], table[i][1], table[i][2], table[i][3], table[i][4]);
    }
    printf("Total:%11d%11d%11d%11d\n\n", table[NUM_PRECINCTS][1], table[NUM_PRECINCTS][2], table[NUM_PRECINCTS][3], table[NUM_PRECINCTS][4]);
    return;
}

/*
    This function declares the winner, if a candidate got more than 50% of the votes,
    or calls for a run off between the top two candidates.
*/
void declare_winner(int table[][NUM_CANDIDATES+1], char names[4]){
    int total_votes = 0;
    int row = NUM_PRECINCTS;
    float pct_votes;
    for (int n = 1; n <= NUM_CANDIDATES; n++){
        total_votes += table[row][n];
    }

    pct_votes = (float)table[row][1] / (float)total_votes;

    if(pct_votes > 0.5)
        printf("Candidate %c is the winner.\n", names[0]);
    else
        printf("Candidates %c and %c will have a runoff.\n", names[0], names[1]);

    return;
}
int main(int argc, char* argv[]) {
//read_file(), show_table(), sort(), and declare_winner()
    FILE* fp = fopen(argv[1], "r");
    if (fp == NULL){
        printf("Error opening file %s\n", argv[1]);
        return -1;
    }

    int table[NUM_PRECINCTS+1][NUM_CANDIDATES+1]; //extra row is for total votes and extra col is for precinct number
    char names[4] = "ABCD";

    read_file(fp, table);
    sort(table, names);
    show_table(table, names);
    declare_winner(table, names);

    fclose(fp);
    return 0;

}


