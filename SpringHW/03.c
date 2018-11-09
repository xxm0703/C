#include <stdio.h>

int are_characters_unique(char *);

int main() {
    printf("%s - %d\n", "alabala", are_characters_unique("alabala"));
    printf("%s - %d\n", "alnbala", are_characters_unique("alnbala"));
    printf("%s - %d\n", "alnbhqj", are_characters_unique("alnbhqj"));

}

int are_characters_unique(char *str) {
    for (int i = 0; str[i + 1]; ++i) {
        for (int j = i + 1; j < str[j]; ++j)
            if (!(str[i] ^ str[j])) return 0;
    }
    return 1;
}
