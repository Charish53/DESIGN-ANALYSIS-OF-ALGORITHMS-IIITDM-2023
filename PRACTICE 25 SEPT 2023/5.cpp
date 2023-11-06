#include <stdio.h>
#include <limits.h>
int min(int a, int b) {
    return a < b ? a : b;
}
int coinChangeWithConstraints(int coins[], int numCoins, int amount, int limits[]) {
    int dp[amount + 1][numCoins + 1];
    // Initialize the DP array
    for (int i = 0; i <= amount; i++) {
        for (int j = 0; j <= numCoins; j++) {
            dp[i][j] = INT_MAX;
        }
    }
    // Base case: no coins needed to make change for 0
    for (int j = 0; j <= numCoins; j++) {
        dp[0][j] = 0;
    }
    // DP calculation
    for (int i = 1; i <= amount; i++) {
        for (int j = 1; j <= numCoins; j++) {
            for (int k = 0; k <= limits[j - 1] && k * coins[j - 1] <= i; k++) {
                if (dp[i - k * coins[j - 1]][j - 1] != INT_MAX) {
                    dp[i][j] = min(dp[i][j], dp[i - k * coins[j - 1]][j - 1] + k);
                }
            }
        }
    }
    return dp[amount][numCoins];
}

int main() {
    int coins[] = {2, 3, 4};
    int numCoins = 3;
    int amount = 9;
    int limits[] = {1, 2, 1}; // Maximum limits for each denomination

    int result = coinChangeWithConstraints(coins, numCoins, amount, limits);

    if (result != INT_MAX) {
        printf("Minimum number of coins required: %d\n", result);
    } else {
        printf("Change cannot be made with the given constraints.\n");
    }

    return 0;
}




