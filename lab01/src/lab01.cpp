#include <stdio.h>

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void selectionSort(int a[], int n) {
    printf("\n--- Selection Sort Started ---\n");
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min_idx])
                min_idx = j;
        }
        swap(&a[min_idx], &a[i]);
        printf("Pass %d: ", i + 1);
        printArray(a, n);
    }
}

void insertionSort(int a[], int n) {
    printf("\n--- Insertion Sort Started ---\n");
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
        printf("Pass %d: ", i);
        printArray(a, n);
    }
}

void bubbleSort(int a[], int n) {
    printf("\n--- Bubble Sort Started ---\n");
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(&a[j], &a[j + 1]);
            }
        }
        printf("Pass %d: ", i + 1);
        printArray(a, n);
    }
}

void exchangeSort(int a[], int n) {
    printf("\n--- Exchange Sort Started ---\n");
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                swap(&a[i], &a[j]);
            }
        }
        printf("Pass %d: ", i + 1);
        printArray(a, n);
    }
}

int main() {
    int n, choice;

    printf("Enter number of elements (n): ");
    scanf("%d", &n);

    int a[n], temp_a[n];
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    while (1) {
        for (int i = 0; i < n; i++) temp_a[i] = a[i];

        printf("\n--- SORTING MENU ---\n");
        printf("1. Selection Sort\n");
        printf("2. Insertion Sort\n");
        printf("3. Bubble Sort\n");
        printf("4. Exchange Sort\n");
        printf("5. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        if (choice == 5) break;

        switch (choice) {
            case 1: selectionSort(temp_a, n); break;
            case 2: insertionSort(temp_a, n); break;
            case 3: bubbleSort(temp_a, n); break;
            case 4: exchangeSort(temp_a, n); break;
            default: printf("Invalid choice!\n");
        }
    }

    return 0;
}