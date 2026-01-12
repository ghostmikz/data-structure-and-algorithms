#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);

    for (int k = low; k <= high; k++)
        printf("%d ", arr[k]);
    printf("\n");

    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        printf("Checking index %d: %d\n", i, arr[i]);
        if (arr[i] == key)
            return i;
    }
    return -1;
}

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        printf("Checking index %d: %d\n", mid, arr[mid]);

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int* arr = new int[n];

    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("\nQuick Sort Steps:\n");
    quickSort(arr, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    int key;
    printf("\nEnter value to search (linear search): ");
    scanf("%d", &key);

    int linearIndex = linearSearch(arr, n, key);
    if (linearIndex != -1)
        printf("Found at index: %d\n", linearIndex);
    else
        printf("Not found\n");

    printf("\nEnter value to search (binary search): ");
    scanf("%d", &key);

    int binaryIndex = binarySearch(arr, n, key);
    if (binaryIndex != -1)
        printf("Found at index: %d\n", binaryIndex);
    else
        printf("Not found\n");

    delete[] arr;
    return 0;
}
