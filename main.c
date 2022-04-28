#include <stdio.h>
#include <stdlib.h>

int main (void) {
    //declare all variables needed for program
    char name1[40];
    char name2[40];
    int rounds;
    int seed;
    int wins1 = 0;
    int wins2 = 0;
    int hand1;
    int hand2;

    printf("Enter player 1: \n");
    scanf("%s", name1);

    printf("Enter player 2: \n");
    scanf("%s", name2);

    printf("How many rounds to play?\n");
    scanf("%d", &rounds);
    while (rounds < 1) {
        printf("Must play at least 1 round! Please try again.\n");
        scanf("%d", &rounds);
    }

    printf("Pick a number to randomize game: \n");
    scanf("%d", &seed);
    printf("\n");
    srand(seed);

    printf("Starting game with %s versus %s for %d rounds!\n", name1, name2, rounds);
    for (int i = 1; i <= rounds; ++i) {
        hand1 = rand() % 3;
        hand2 = rand() % 3;
        if (hand1 == hand2) {
            printf("Round %d is a TIE\n", i);
        } else if (hand1 == 0 && hand2 == 1) {
            // rock vs paper
            printf("%s wins Round %d with PAPER\n", name2, i);
            ++wins2;
        } else if (hand1 == 0 && hand2 == 2) {
            // rock vs scissor
            printf("%s wins Round %d with ROCK\n", name1, i);
            ++wins1;
        } else if (hand1 == 1 && hand2 == 2) {
            // paper vs scissor
            printf("%s wins Round %d with SCISSORS\n", name2, i);
            ++wins2;
        } else if (hand1 == 1 && hand2 == 0) {
            // paper vs rock
            printf("%s wins Round %d with PAPER\n", name1, i);
            ++wins1;
        } else if (hand1 == 2 && hand2 == 0) {
            // scissor vs rock
            printf("%s wins Round %d with ROCK\n", name2, i);
            ++wins2;
        } else if (hand1 == 2 && hand2 == 1) {
            // scissor vs paper
            printf("%s wins Round %d with SCISSORS\n", name1, i);
            ++wins1;
        }
    }

    printf("\n");
    printf("%s wins %d and %s wins %d.\n", name1, wins1, name2, wins2);

    if (wins1 > wins2) {
        printf("GAME WINNER - %s!\n", name1);
    } else if (wins2 > wins1) {
        printf("GAME WINNER - %s!\n", name2);
    } else {
        printf("Tie!\n");
    }
    
    return 0;
}