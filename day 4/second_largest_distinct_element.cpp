#include <stdio.h>

int secondLargestDistinct(int arr[], int n) {
    int firstLargest = -1, secondLargest = -1;

    for (int i = 0; i < n; i++) {
        if (arr[i] > firstLargest) {
            secondLargest = firstLargest;
            firstLargest = arr[i];
        } else if (arr[i] > secondLargest && arr[i] != firstLargest) {
            secondLargest = arr[i];
        }
    }

    return secondLargest;
}

int main() {
    int N;


    printf("Enter the size of the array: ");
    scanf("%d", &N);

    int Arr[N];

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < N; i++) {
        scanf("%d", &Arr[i]);
    }

    int result = secondLargestDistinct(Arr, N);

    
    printf("The second largest distinct element is: %d\n", result);

    return 0;
}
