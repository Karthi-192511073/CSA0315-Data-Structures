#include <stdio.h>

int main() {
    int arr[100], n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    if (n < 5) {
        printf("Array has less than 5 elements! Cannot display 5th element.\n");
    } else {
        printf("The 5th iterated element is: %d\n", arr[4]);  // Index 4 ? 5th element
    }
    return 0;
}

