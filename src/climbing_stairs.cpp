#include "climbing_stairs.h"

int Solution::climbStairs(int n) {
    if (n <= 2) {
        return n;
    }

    int total = 0;
    int prev1 = 2;
    int prev2 = 1;
    for (int i = 3; i <= n; i++) {
        total = prev1 + prev2;
        prev2 = prev1;
        prev1 = total;
    }
    return total;
}
