#include<stdio.h>

void dansketal(int number, char* result);

int main() {
    while(1) {
        int number;
        printf("Enter a number: ");
        scanf("%d", &number);
        char result[256] = {0}; // Buffer to hold the string because I don't know how long the string will be, thanks stackoverflow.
        dansketal(number, result);
        printf("%s\n", result);
    }
    return 0;
}