#include <stdio.h>

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Return the index where the target was found
        }
    }
    return -1; // Return -1 if target was not found in the array
}

int main() {
    int arr[] = {12, 34, 56, 78, 90, 23, 45, 67};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;

    printf("Enter the number to search: ");
    scanf("%d", &target);

    int index = linearSearch(arr, size, target);

    if (index != -1) {
        printf("Number found at index %d\n", index);
    } else {
        printf("Number not found in the array.\n");
    }

    return 0;
}

