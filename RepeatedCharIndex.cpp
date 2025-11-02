#include <stdio.h>

int main() {
    int arr[100], n, i, j;
    int flag = 0;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nIndexes of repeated elements:\n");

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                printf("Element %d repeated at indexes %d and %d\n", arr[i], i, j);
                flag = 1;
            }
        }
    }

    if (flag!=1)
        printf("No repeated elements found.\n");
}
