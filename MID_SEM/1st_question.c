#include <stdio.h>

void swap(int *a, int *b) { //swap function
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

int inversion(int s[], int n) { //i) Function to count inversion pairs
    int c = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (s[i] > s[j]) {
                c++;
            }
        }
    }
    return c;
}

void insertion(int v[], int n) {
    //ii) to remove all inversion pairs insertion sort algorithm is used as above logic
    int comp = 0;
    int swaps = 0;
    for (int i = 1; i < n; i++) { // Change i <= n-1 to i < n
        for (int j = i; (j > 0&&++comp) && v[j - 1] > v[j]; j--) {
            
            swap(&v[j], &v[j - 1]); // Use the swap function
            swaps++;
        }
    }
    printf("no of comparisons = %d\n", comp);// no of comparisons 
    printf("no of swaps = %d\n", swaps);// no of swaps
    
}

int main() {
    int size;
    scanf("%d", &size);
    int a[size];
    for (int i = 0; i < size; i++) {
        scanf("%d", &a[i]);
    }
    int count = inversion(a, size);
    printf("\ninversion pairs = %d\n", count);
    insertion(a, size);

    printf("Sorted Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
