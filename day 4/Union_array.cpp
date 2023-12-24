#include <stdio.h>
void printUnion(int arr1[], int size1, int arr2[], int size2) {
    int i = 0, j = 0;

    printf("Union of the two arrays: ");

    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            printf("%d ", arr1[i++]);
        } else if (arr2[j] < arr1[i]) {
            printf("%d ", arr2[j++]);
        } else {
            
            printf("%d ", arr1[i++]);
            j++;
        }
    }

    
    while (i < size1) {
        printf("%d ", arr1[i++]);
    }

    
    while (j < size2) {
        printf("%d ", arr2[j++]);
    }

    printf("\n");
}

int main() {
    int size1, size2;

    printf("Enter the size of the first sorted array: ");
    scanf("%d", &size1);

    int arr1[size1];

    printf("Enter the elements of the first sorted array: ");
    for (int i = 0; i < size1; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter the size of the second sorted array: ");
    scanf("%d", &size2);

    int arr2[size2];

    printf("Enter the elements of the second sorted array: ");
    for (int i = 0; i < size2; i++) {
        scanf("%d", &arr2[i]);
    }

    printUnion(arr1, size1, arr2, size2);

    return 0;
}

