#include <stdio.h>

int main() {
    int arr[100], n, i, j, count;
    int visited[100] = {0};  

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nFrequency of repeated elements:\n");

    for (i = 0; i < n; i++) {
        if (visited[i] == 1)
            continue;

        count = 1;

        for (j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                visited[j] = 1;  
            }
        }

        if (count > 1) {
            printf("Element %d is repeated %d times\n", arr[i], count);
        }
    }
}

