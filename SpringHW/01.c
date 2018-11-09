#include <string.h>
#include <stdio.h>

typedef struct game_t {
    short id;
    float price;
    char zip[3];
} game_t;

int is_game_available(game_t, char *);

int how_many_available(game_t *, char *);

int main() {
    game_t games[] = {{1, 2.5, "BG"}, {2, 5.3, "A"}, {3, 1.8, "BG"}};
    printf("%d\n%d\n", is_game_available(games[0],"BG"), is_game_available(games[1], "BG"));
    printf("%d", how_many_available(games, "BG"));
    return 0;
}

int is_game_available(game_t game, char *string) {
    return !strcmp(game.zip, string);
}

int how_many_available(game_t games[3], char *string) {
    int count = 0;
    for (int i = 0; i < 10; ++i) {
        count += is_game_available(games[i], string);
    }
    return count;
}