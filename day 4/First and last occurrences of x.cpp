#include <stdio.h>
int firstOccurrence(int arr[], int n, int x) {
    int low = 0, high = n - 1, result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x) {
            result = mid;
            high = mid - 1; 
        } else if (arr[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return result;
}
int lastOccurrence(int arr[], int n, int x) {
    int low = 0, high = n - 1, result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x) {
            result = mid;
            low = mid + 1; 
        } else if (arr[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return result;
}

int main() {
    int n, x;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the value of x: ");
    scanf("%d", &x);
    int first = firstOccurrence(arr, n, x);
    int last = lastOccurrence(arr, n, x);
    if (first != -1 && last != -1) {
        printf("First occurrence of %d is at index %d and last occurrence is at index %d\n", x, first, last);
    } else {
        printf("%d not found in the array\n", x);
    }

    return 0;
}
