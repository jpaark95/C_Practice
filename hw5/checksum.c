#include <stdio.h>

int main() {
    int ch;
    int checksum = 0;
    
    printf("Line: ");

    while(1){
        ch = getchar();
        if (ch != '\n')
            checksum += ch;
        else
            printf("Line: ");

        if (checksum == '.')
            break;

        if (ch == '.'){
            checksum = checksum % 64 + (int)' ';
            printf("Checksum: %c\n", checksum);
            checksum = 0;
        }
    }

    return 0;
}