#include "best_time_to_buy_and_sell_stock.h"

int Solution::maxProfit(vector<int>& prices) {
    int maximumProfit = 0;
    int minimumPrice = prices[0];
    for (auto &price: prices) {
        if (price < minimumPrice) {
            minimumPrice = price;
        } else {
            maximumProfit = (price - minimumPrice > maximumProfit) ? 
                price - minimumPrice : maximumProfit;
        }
    }
    return maximumProfit;
}
