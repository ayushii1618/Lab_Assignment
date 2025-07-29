#include <stdio.h>
#include <string.h>

int main() {
    char str[100], temp;
    int i, len;

    // Input string from user
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline character if present
    len = strlen(str);
    if (str[len - 1] == '\n') {
        str[len - 1] = '\0';
        len--;
    }

    // Reverse the string in place
    for (i = 0; i < len / 2; i++) {
        temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }

    // Output reversed string
    printf("Reversed string: %s\n", str);

    return 0;
}
