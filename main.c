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
    puts("Input receiver");
    gets(temp);
    fprintf(fout, "Dear %s,\n", temp);
    while (!feof(fin)) {
        fgets(temp, 99, fin);
        fputs(temp, fout);
    }
    puts("Input sender");
    gets(temp);
    fprintf(fout, "\nYour %s", temp);
    fclose(fin);
    fclose(fout);
    return 0;
}
