#include <stdio.h>

int main() {
    int n, i, sum = 0, expectedSum, missing;
    int arr[100];

    printf("Enter the number of elements (including missing number): ");
    scanf("%d", &n);

    printf("Enter %d elements (one number in 1 to %d range is missing):\n", n - 1, n);
    for (i = 0; i < n - 1; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    expectedSum = n * (n + 1) / 2;
    missing = expectedSum - sum;

    printf("\nThe missing element is: %d\n", missing);

    return 0;
}

