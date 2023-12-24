 #include <stdio.h>


int hasPairWithSum(int arr[], int n, int X) {
    
    int present[X + 1];
    for (int i = 0; i <= X; i++) {
        present[i] = 0;
    }

    for (int i = 0; i < n; i++) {
           if (present[X - arr[i]]) {
            return 1; 
        }

         present[arr[i]] = 1;
    }

    return 0; 
}

int main() {
    int N, X;

    
    printf("Enter the size of the array: ");
    scanf("%d", &N);

     int Arr[N];
   printf("Enter the elements of the array:\n");
    for (int i = 0; i < N; i++) {
        scanf("%d", &Arr[i]);
    }

    printf("Enter the value of X: ");
    scanf("%d", &X);

    int result = hasPairWithSum(Arr, N, X);
        if (result) {
        printf("Yes, there exist two elements whose sum is %d\n", X);
    } else {
        printf("No, there are no two elements whose sum is %d\n", X);
    }

    return 0;
}
