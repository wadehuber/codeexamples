#include <stdio.h>

#define STUDENTS 3
#define QUIZZES 4

void printScores(int scores[][QUIZZES], int students) {
    // When passing a 2D array to a function, C needs to know
    // the size of the second dimension to find each row correctly.

    for (int i = 0; i < students; i++) {
        printf("Student %d: ", i + 1);

        for (int j = 0; j < QUIZZES; j++) {
            printf("%d ", scores[i][j]);
        }

        printf("\n");
    }
}

int main(void) {
    int scores[STUDENTS][QUIZZES] = {
        {98, 97, 99, 100},
        {72, 68, 74, 70},
        {88, 76, 95, 89},
    };

    printScores(scores, STUDENTS);

    return 0;
}