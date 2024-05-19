#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

int main(void) {
    FILE *fin, *fout;
    if ((fin = fopen("a.txt", "r")) == NULL) {
        puts("Error opening input file");
        exit(1);
    }
    if ((fout = fopen("b.txt", "w")) == NULL) {
        puts("Error opening output file");
        exit(1);
    }
    char temp[100];
    while (!feof(fin)) {
        fgets(temp, 99, fin);
        char *ch;
        if ((ch = strstr(temp, "%receiver%")) != NULL) {
            puts("Input receiver");
            char receiver[50];
            fgets(receiver, 49, stdin);
            strcpy(ch, receiver);
        }
        if ((ch = strstr(temp, "%sender%")) != NULL) {
            puts("Input sender");
            char sender[50];
            fgets(sender, 49, stdin);
            strcpy(ch, sender);
        }
        fputs(temp, fout);
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
