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

    
    for (int i = 0; i < students; i++) {
        scanf("%s", Name[i]);
        capitalize(Name[i]);     
        for (int j = 0; j < tests; j++) {
            scanf("%d", &Scores[i][j]);
        }
    }

   
    float averages[students];
    for (int i = 0; i < students; i++) {
        int sum = 0;
        for (int j = 0; j < tests; j++) {
            sum += Scores[i][j];
        }
        averages[i] = sum / (float)tests;
    }

   
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

    
    for (int i = 0; i < 3; i++) {
        printf("%s\n", Name[i]);
    }

    return 0;
}

