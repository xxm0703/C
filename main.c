#include <stdio.h>
#include <io.h>
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <conio.h>

int main() {
    FILE *f;
    struct dirent *dp;
    DIR *dirp = opendir(".");
    char opts[10][20];
    int i = 0, k = 1;
    char s[80], nav;
    while ((dp = readdir(dirp)) != NULL){
            if (dp->d_name[dp->d_namlen-1] == 'c') strcpy(opts[i++], dp->d_name);
    }
    closedir(dirp);

    do{
        if(k > i) k = 0;
        if(k == 0) printf("> Exit\n");
        else printf("  Exit\n");
        for (int j = 0; j < i; j++) {
            if (j == k-1) printf("> %s\n", opts[j]);
            else printf("  %s\n", opts[j]);
        }
        nav = (char)getche();
        switch (nav){
            case 'w': //arrow_up
                k--;
                system("cls");
                break;
            case 's':
                k++;
                system("cls");
                break;
            case 'o':
                system("cls");
                f = fopen(opts[k-1], "r");
                if(f){
                    while (fgets(s, 80, f)){
                        printf("%s", s);
                    }
                    printf("\nPress key to continue...\a");
                    getchar();
                    system("cls");
                }
                break;
            default:
              /*  system("cls");
                printf("No option");
                printf("\nPress key to continue...\a");
            */    getchar();
                system("cls");
        }

    }while (k != 0 || nav != 'o');
    return 0;
}