#include "gas_station.h"

// gas = [1, 2, 3, 4, 5]
// cost = [3, 4, 5, 1, 2]
// gainGas = [-2, -2, -2, 3, 3]
// sum = [-2, -4, -6, -3, 0]
int Solution::canCompleteCircuit1(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();
    int head = 0;
    vector<int> gainGas(n, 0);
    for (int i = 0; i < n; i++)
        gainGas[i] = gas[i] - cost[i];

    int sum = 0, borrow = 0;
    for (int i = 0; i < n; i++) {
        sum += gainGas[i];
        while (i < n && sum + borrow < 0) {
            borrow -= gainGas[head++];
        }
    }
    if (sum < 0 || head >= n) {
        return -1;
    }
    return head;
}

// gas     = [1, 2, 3, 4, 5]
// cost    = [3, 4, 5, 1, 2]
// gainGas = [-2, -2, -2, 3, 3]
// gainGas = [0, 1, 2, -1, 3] -> 0
// gainGas = [0, 1, 2, -100, 3, 1, 2] -> 4
int Solution::canCompleteCircuit2(vector<int>& gas, vector<int>& cost) {
    int start = 0;
    int currGas = 0, totalGas = 0;
    for (int i = 0; i < gas.size(); i++) {
        int gainGas = gas[i] - cost[i];
        currGas += gainGas;
        totalGas += gainGas;

        if (currGas < 0) {
            currGas = 0;
            start = i + 1;
        }
    }
    return totalGas < 0 ? -1 : start;
}
