#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number within a given range
int generate_random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to display a question and options
void display_question(const char *question, const char *options[]) {
    printf("%s\n", question);
    for (int i = 0; i < 4; i++) {
        printf("%d. %s\n", i + 1, options[i]);
    }
}

int main() {
    int score = 0;
    int num_questions = 5; // Number of questions in the quiz

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Questions and answers
    const char *questions[] = {
        "What is the capital of France?",
        "Which planet is known as the 'Red Planet'?",
        "Who painted the Mona Lisa?",
        "Which country is known for its famous pyramids?",
        "Which scientist formulated the theory of relativity?"
    };

    const char *options[][4] = {
        {"London", "Paris", "Berlin", "Rome"},
        {"Venus", "Mars", "Jupiter", "Mercury"},
        {"Vincent van Gogh", "Pablo Picasso", "Leonardo da Vinci", "Michelangelo"},
        {"India", "Egypt", "Brazil", "China"},
        {"Isaac Newton", "Albert Einstein", "Galileo Galilei", "Stephen Hawking"}
    };

    const int correct_answers[] = {2, 2, 3, 2, 2};

    printf("Welcome to the Quiz Game!\n");

    for (int i = 0; i < num_questions; i++) {
        int index = generate_random_number(0, 4);

        display_question(questions[index], options[index]);

        int answer;
        printf("Enter your answer (1-4): ");
        scanf("%d", &answer);

        if (answer >= 1 && answer <= 4) {
            if (answer == correct_answers[index]) {
                printf("Correct!\n");
                score++;
            } else {
                printf("Incorrect. The correct answer is: %d. %s\n", correct_answers[index], options[index][correct_answers[index] - 1]);
            }
        } else {
            printf("Invalid input. Please enter a number between 1 and 4.\n");
        }

        printf("\n");
    }

    printf("Your final score: %d out of %d\n", score, num_questions);

    return 0;
}
