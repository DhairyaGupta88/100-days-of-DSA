//A secret system stores code names in forward order. To display them in mirror format, you must transform the given code name so that its characters appear in the opposite order.
#include <stdio.h>

void reverse(char str[], int index) {
    // Base case
    if (str[index] == '\0')
        return;

    // Recursive call
    reverse(str, index + 1);

    // Print character while returning
    printf("%c", str[index]);
}

int main() {
    char code[100];

    printf("Enter the code name: ");
    scanf("%s", code);

    printf("Mirror format: ");
    reverse(code, 0);

    return 0;
}
