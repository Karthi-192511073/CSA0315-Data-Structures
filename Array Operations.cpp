#include <stdio.h>

#define MAX 100  

int main() {
    int arr[MAX];
    int n, choice, pos, element, i;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    while (1) {
        printf("\n--- Array Operations Menu ---\n");
        printf("1. Display Array\n");
        printf("2. Insert Element\n");
        printf("3. Delete Element\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Array elements: ");
                for (i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;

            case 2:
                if (n == MAX) {
                    printf("Array is full. Insertion not possible.\n");
                    break;
                }
                printf("Enter position to insert (1 to %d): ", n + 1);
                scanf("%d", &pos);
                if (pos < 1 || pos > n + 1) {
                    printf("Invalid position!\n");
                    break;
                }
                printf("Enter element to insert: ");
                scanf("%d", &element);

                for (i = n; i >= pos; i--) {
                    arr[i] = arr[i - 1];
                }
                arr[pos - 1] = element;
                n++;
                printf("Element inserted successfully!\n");
                break;

            case 3:
                if (n == 0) {
                    printf("Array is empty. Deletion not possible.\n");
                    break;
                }
                printf("Enter position to delete (1 to %d): ", n);
                scanf("%d", &pos);
                if (pos < 1 || pos > n) {
                    printf("Invalid position!\n");
                    break;
                }

                for (i = pos - 1; i < n - 1; i++) {
                    arr[i] = arr[i + 1];
                }
                n--;
                printf("Element deleted successfully!\n");
                break;

            case 4:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

