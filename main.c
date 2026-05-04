#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define STUDENTS 5
#define TESTS 13

// Funktion för att formatera namnet: Stor bokstav först, resten små.
void format_name(char *name) {
    if (name[0] != '\0') {
        name[0] = toupper(name[0]);
        for (int i = 1; name[i] != '\0'; i++) {
            name[i] = tolower(name[i]);
        }
    }
}

int main() {
    char names[STUDENTS][11]; // Max 10 tecken enligt specifikation + nollterminator
    int scores[STUDENTS][TESTS];
    float averages[STUDENTS];
    float total_class_sum = 0;

    // 1. Inläsning
    for (int i = 0; i < STUDENTS; i++) {
        // Läser in namn (max 10 tecken)
        if (scanf("%10s", names[i]) != 1) break;
        format_name(names[i]);

        int student_sum = 0;
        for (int j = 0; j < TESTS; j++) {
            scanf("%d", &scores[i][j]);
            student_sum += scores[i][j];
        }
        
        // Beräkna medelvärde för denna elev
        averages[i] = (float)student_sum / TESTS;
        
        // Lägg till i klassens totala summa för senare beräkning av snitt
        total_class_sum += student_sum;
    }

    // Beräkna klassens totala medelvärde
    float class_average = total_class_sum / (STUDENTS * TESTS);

    // 2. Analys: Identifiera elev med högst medelpoäng
    int best_student_index = 0;
    for (int i = 1; i < STUDENTS; i++) {
        if (averages[i] > averages[best_student_index]) {
            best_student_index = i;
        }
    }

    // UTSKRIFT: Namnet på eleven med högst medelpoäng
    printf("%s\n", names[best_student_index]);

    // 3. Analys: Identifiera elever under gruppens snitt
    // Vi loopar igenom i originalordning (0 till 4)
    for (int i = 0; i < STUDENTS; i++) {
        if (averages[i] < class_average) {
            printf("%s\n", names[i]);
        }
    }

    return 0;
}
