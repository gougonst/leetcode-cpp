#include "coin_change.h"
#include <algorithm>
#include <iostream>

int Solution::coinChange1(vector<int>& coins, int amount) {
    int n = coins.size();
    int dp[n + 1][amount + 1];

    // amount = 0, cost 0 coin
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= amount; j++) {
            if (j == 0)
                dp[i][0] = 0;
            else
                dp[i][j] = __INT32_MAX__;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= amount; j++) {
            for (int k = 0; k <= j / coins[i - 1]; k++) {
                if (dp[i - 1][j - k * coins[i - 1]] == __INT32_MAX__)
                    continue;
                dp[i][j] = min(dp[i][j], dp[i - 1][j - k * coins[i - 1]] + k);
            }
        }
    }

    int ans = __INT32_MAX__;
    for (int i = 0; i < n + 1; i++)
        ans = min(ans, dp[i][amount]);
    if (ans == __INT32_MAX__)
        ans = -1;
    return ans;
}

int Solution::coinChange2(vector<int>& coins, int amount) {
    int dp[amount + 1];

    dp[0] = 0;
    for (int j = 1; j <= amount; j++) {
        dp[j] = __INT32_MAX__;
        for (int& coin: coins) {
            for (int k = 1; k * coin <= j; k++) {
                if (dp[j - coin * k] == __INT32_MAX__)
                    continue;
                dp[j] = min(dp[j], dp[j - coin * k] + k);
            }
        }
    }

    return dp[amount] == __INT32_MAX__ ? -1 : dp[amount];
}

int Solution::coinChange3(vector<int>& coins, int amount) {
    int dp[amount + 1];

    dp[0] = 0;
    for (int j = 1; j <= amount; j++) {
        dp[j] = __INT32_MAX__;
        for (int& coin: coins) {
            if (j - coin < 0 || dp[j - coin] == __INT32_MAX__)
                continue;
            dp[j] = min(dp[j], dp[j - coin] + 1);
        }
    }

    return dp[amount] == __INT32_MAX__ ? -1 : dp[amount];
}
