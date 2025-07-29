#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_LENGTH 50

// Function to convert a string to lowercase
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++)
        str[i] = tolower(str[i]);
}

// Function to remove punctuation from a word
void removePunctuation(char *word) {
    int i, j = 0;
    char clean[MAX_LENGTH];
    for (i = 0; word[i] != '\0'; i++) {
        if (isalnum(word[i]))
            clean[j++] = word[i];
    }
    clean[j] = '\0';
    strcpy(word, clean);
}

int main() {
    char paragraph[1000];
    char words[MAX_WORDS][MAX_LENGTH];
    int freq[MAX_WORDS] = {0};
    int wordCount = 0;

    // Input paragraph
    printf("Enter a paragraph:\n");
    fgets(paragraph, sizeof(paragraph), stdin);

    // Tokenize paragraph into words
    char *token = strtok(paragraph, " \n\t");

    while (token != NULL) {
        char word[MAX_LENGTH];
        strncpy(word, token, MAX_LENGTH);
        toLowerCase(word);
        removePunctuation(word);

        // Check if word already exists
        int found = 0;
        for (int i = 0; i < wordCount; i++) {
            if (strcmp(words[i], word) == 0) {
                freq[i]++;
                found = 1;
                break;
            }
        }

        // If not found, add new word
        if (!found && strlen(word) > 0) {
            strcpy(words[wordCount], word);
            freq[wordCount] = 1;
            wordCount++;
        }

        token = strtok(NULL, " \n\t");
    }

    // Print word frequencies
    printf("\nWord Frequencies:\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s: %d\n", words[i], freq[i]);
    }

    return 0;
}
