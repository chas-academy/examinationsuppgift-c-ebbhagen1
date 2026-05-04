#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define students 5
#define tests 13

void capitalize(char *name) {
    name[0] = toupper(name[0]);
    for (int i = 1; name[i] != '\0'; i++) {
        name[i] = tolower(name[i]);
    }
}

int main() {
    char Name[students][50];
    int Scores[students][tests];

    // Inmatning
    for (int i = 0; i < students; i++) {
        scanf("%49s", Name[i]);
        capitalize(Name[i]);

        for (int j = 0; j < tests; j++) {
            scanf("%d", &Scores[i][j]);
        }
    }

    // Beräkna medelvärde per elev
    float averages[students];
    for (int i = 0; i < students; i++) {
        int sum = 0;
        for (int j = 0; j < tests; j++) {
            sum += Scores[i][j];
        }
        averages[i] = sum / (float)tests;
    }

    // Beräkna klassens totala medelvärde
    float class_total = 0;
    for (int i = 0; i < students; i++) {
        for (int j = 0; j < tests; j++) {
            class_total += Scores[i][j];
        }
    }
    float class_average = class_total / (students * tests);

    // Skriv ut elever under klassens medelvärde (i originalordning)
    printf("Elever under klassens medelvärde:\n");
    for (int i = 0; i < students; i++) {
        if (averages[i] < class_average) {
            printf("%s\n", Name[i]);
        }
    }

    // Sortera för att hitta topp 3 (din ursprungliga sortering)
    for (int i = 0; i < students - 1; i++) {
        for (int j = 0; j < students - i - 1; j++) {
            if (averages[j] < averages[j + 1]) {

                float temp_avg = averages[j];
                averages[j] = averages[j + 1];
                averages[j + 1] = temp_avg;

                char temp_name[50];
                strcpy(temp_name, Name[j]);
                strcpy(Name[j], Name[j + 1]);
                strcpy(Name[j + 1], temp_name);
            }
        }
    }

    // Skriv ut topp 3
    printf("\nTopp 3:\n");
    for (int i = 0; i < 3; i++) {
        printf("%s\n", Name[i]);
    }

    return 0;
}
