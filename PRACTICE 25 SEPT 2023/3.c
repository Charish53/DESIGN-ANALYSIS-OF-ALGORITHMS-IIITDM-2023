#include <stdio.h>
#include<limits.h>
//dynamic programming for R1,R2,....,Rk.
int minCoins(int coins[], int n, int target_amount) {
    int dp[target_amount + 1];
    dp[0] = 0;

    for (int i = 1; i <= target_amount; i++) {
        dp[i] = INT_MAX; // Initialize with a large value

        for (int j = 0; j < n; j++) {
            if (coins[j] <= i && dp[i - coins[j]] != INT_MAX) {
                int subproblem = dp[i - coins[j]] + 1;
                if (subproblem < dp[i]) {
                    dp[i] = subproblem;
                }
            }
        }
    }

    return dp[target_amount];
}

int main() {
    int coins[] = {1, 5, 10, 25};
    int n = sizeof(coins) / sizeof(coins[0]);
    int target_amount = 63;

    int min_coins_needed = minCoins(coins, n, target_amount);

    printf("Minimum number of coins needed for %d cents: %d\n", target_amount, min_coins_needed);

    return 0;
}




