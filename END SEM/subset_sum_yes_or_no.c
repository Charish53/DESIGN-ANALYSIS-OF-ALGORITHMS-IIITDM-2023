// print yes or no for subset
#include <stdio.h>
#include <stdbool.h>

bool isSubsetSum(int arr[], int n, int k) {
    bool dp[n + 1][k + 1];

    // Initialize the dp table
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            if (j == 0) {
                dp[i][j] = true;
            } else if (i == 0) {
                dp[i][j] = false;
            } else if (arr[i - 1] <= j) {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][k];
}

int main() {
    int n, k;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &k);

    if (isSubsetSum(arr, n, k)) {
        printf("yes\n");
    } else {
        printf("no\n");
    }

    return 0;
}
