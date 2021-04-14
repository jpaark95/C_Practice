#include <stdio.h>
#include <string.h>

char my_tolower(char n) {
    if ( 65 <= n && n <= 90 ) //capital letter
        return n + 32;
    
    if ( !(97 <= n && n <= 122) ) //if not lower case letter
        return '0';
    else //its a lower case letter
        return n;
}

void my_getch(char* temp, char* instr) {
    scanf(" %s", temp);
    *instr = temp[0];
    *instr = my_tolower(*instr);

}

void get_input(char* bread_type, char* loaf_size, char* baking_style) {
    char bread_typ, loaf_sz, baking_st;
    char tmp[25];

    do { //getting valid input from user for white or sweet bread
        printf("Are you making white or sweet bread? (w or s)? ");
        my_getch(tmp, &bread_typ);
        if (bread_typ != 'w' && bread_typ != 's')
            printf("Please enter w or s\n");

    } while (!(bread_typ == 'w' || bread_typ == 's'));
    *bread_type = bread_typ;
    memset(tmp, 0, sizeof(tmp));

    do {
        printf("Is this a single or double loaf (s or d)? ");
        my_getch(tmp, &loaf_sz);

        if (loaf_sz != 's' && loaf_sz != 'd')
            printf("Please enter d or s\n");
    } while(!(loaf_sz == 's' || loaf_sz == 'd'));
    *loaf_size = loaf_sz;
    memset(tmp, 0, sizeof(tmp));

    do {
        printf("Are you going to bake manually (y or n)? ");
        my_getch(tmp, &baking_st);
        if(baking_st != 'y' && baking_st != 'n')
            printf("Please enter y or n\n");
    } while(!(baking_st == 'y' || baking_st == 'n'));
    *baking_style = baking_st;
}

void calc_baking_time(char bread_type, char loaf_size, char baking_style){
    int knead_p, rise_p, knead_s, rise_s, rise_f, cooling, total_time_min, total_time_sec;
    float bake_time;
    int loaf_shape = 2;

    if (bread_type == 'w') {
        knead_p = 15; rise_p = 60; knead_s = 18; rise_s = 20; rise_f = 75; cooling = 30; bake_time = 45;
        total_time_min = knead_p + rise_p + knead_s + rise_s;
        total_time_sec = loaf_shape;
    } else { //breadtype is sweet
        knead_p = 20; rise_p = 60; knead_s = 33; rise_s = 30; rise_f = 75; cooling = 30; bake_time = 35;
        total_time_min = knead_p + rise_p + knead_s + rise_s;
        total_time_sec = loaf_shape;
    }

    printf("Primary kneading: %d minutes\n", knead_p);
    printf("Primary rising: %d minutes\n", rise_p);
    printf("Secondary kneading: %d minutes\n", knead_s);
    printf("Secondary rising: %d minutes\n", rise_s);
    printf("Loaf shaping: %d seconds\n", loaf_shape);
    if (baking_style == 'y'){
            printf("You should remove the dough for manual baking.\n");
            printf("\nFor a total baking time of %d minutes and %d seconds.\n", total_time_min, total_time_sec);
            return;
        } else { //baking style not manual
            
            if (loaf_size == 'd')
                bake_time *= 1.5;
            printf("Final rising: %d minutes\n", rise_f);
            printf("Baking: %d minutes %d seconds\n", (int)bake_time,  (int)((bake_time - (int)bake_time)*60) );
            total_time_min += (int)bake_time + rise_f + cooling;
            total_time_sec = (int)((bake_time - (int)bake_time)*60 + loaf_shape);
            printf("\nFor a total baking time of %d minutes and %d seconds.\n", total_time_min, total_time_sec);
            
        }
}
int main() {
    char bread_type, loaf_size, baking_style;

    get_input(&bread_type, &loaf_size, &baking_style);
    
    printf("%c%c%c\n", bread_type, loaf_size, baking_style);
    calc_baking_time(bread_type, loaf_size, baking_style);

    return 0;
}