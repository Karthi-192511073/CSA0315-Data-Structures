#include <stdio.h>

int main() {
    int arr[100], n, i, key, flag = 0;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &key);

    for (i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("Element %d found at position %d.\n", key, i + 1);
            flag = 1;
            break;
        }
    }

    if (flag!=1) {
        printf("Element %d not found in the array.\n", key);
    }

    
}

