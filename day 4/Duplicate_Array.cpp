#include <stdio.h>
#include <stdlib.h>

int* findDuplicates(int arr[], int size, int* resultSize) {
    int* counts = (int*)calloc(size, sizeof(int));
    int duplicateCount = 0;

    
    for (int i = 0; i < size; i++) {
        counts[arr[i]]++;
    }

    for (int i = 0; i < size; i++) {
        if (counts[i] > 1) {
            duplicateCount++;
        }
    }

    
    int* duplicates = (int*)malloc(duplicateCount * sizeof(int));
    int index = 0;


    for (int i = 0; i < size; i++) {
        if (counts[arr[i]] > 1) {
            duplicates[index++] = arr[i];
            counts[arr[i]] = 0; 
        }
    }

    free(counts);

    if (duplicateCount == 0) {
        *resultSize = 1;
        duplicates[0] = -1; 
    } else {
        *resultSize = duplicateCount;
    }

    return duplicates;
}

int main() {
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if (size <= 0) {
        printf("Invalid array size\n");
        return 1;
    }

    int* arr = (int*)malloc(size * sizeof(int));

    printf("Enter the elements of the array (0 to %d): ", size - 1);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] < 0 || arr[i] >= size) {
            printf("Invalid element. Element must be between 0 and %d.\n", size - 1);
            free(arr);
            return 1;
        }
    }

    int resultSize;
    int* duplicates = findDuplicates(arr, size, &resultSize);

    printf("Duplicates in ascending order: [");
    for (int i = 0; i < resultSize; i++) {
        printf("%d", duplicates[i]);
        if (i < resultSize - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    free(arr);
    free(duplicates);

    return 0;
}

