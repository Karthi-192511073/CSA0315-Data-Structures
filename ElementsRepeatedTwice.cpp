#include <stdio.h>

int main() {
    int arr[100], n, i, j, count;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nElements repeated twice:\n");
    for (i = 0; i < n; i++) {
        count = 0;
        for (j = 0; j < n; j++) {
            if (arr[i] == arr[j])
                count++;
        }
        if (count == 2) {
            printf("%d ", arr[i]);
            for (j = i + 1; j < n; j++) {
                if (arr[i] == arr[j])
                    arr[j] = -1; 
            }
        }
    }
}

