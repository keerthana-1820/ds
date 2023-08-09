
#include <stdio.h>

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num % 2 == 0) {
        printf("%d is ev#en.\n", num);
    } else {
        printf("%d is odd.\n", num);
    }

    return 0;
}
