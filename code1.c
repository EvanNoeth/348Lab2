#include <stdio.h>

void find_combinations(int score, int index, int current_combination[], int scoring_plays[], int n);
void print_combination(int current_combination[], int scoring_plays[], int n);

int main() {
    int scoring_plays[] = {8, 7, 6, 3, 2};
    int n = sizeof(scoring_plays) / sizeof(scoring_plays[0]);
    int score;

    while (1) {
        printf("Enter the NFL score (0 or 1 to STOP): ");
        scanf("%d", &score);

        if (score <= 1) {
            printf("Program terminated.\n");
            break;
        }

        printf("Possible combinations of scoring plays if a team’s score is %d:\n", score);
        int current_combination[n];
        
        for (int i = 0; i < n; i++) {
            current_combination[i] = 0;
        }
        
        find_combinations(score, 0, current_combination, scoring_plays, n);
    }

    return 0;
}


void find_combinations(int score, int index, int current_combination[], int scoring_plays[], int n) {
    if (score == 0) {
        print_combination(current_combination, scoring_plays, n);
        return;
    }

    if (score < 0 || index == n) {
        return;
    }

    current_combination[index]++;
    find_combinations(score - scoring_plays[index], index, current_combination, scoring_plays, n);

    current_combination[index]--;
    find_combinations(score, index + 1, current_combination, scoring_plays, n);
}

void print_combination(int current_combination[], int scoring_plays[], int n) {
    const char *play_names[] = {
        "TD + 2pt",
        "TD + FG",
        "TD",
        "3pt FG",
        "Safety"
    };

    int first = 1;

    for (int i = 0; i < n; i++) {
        if (current_combination[i] > 0) {
            if (!first) {
                printf(", ");
            }
            first = 0;
            printf("%d %s", current_combination[i], play_names[i]);
        }
    }
    printf("\n");
}
