#include "evaluate_reverse_polish_notation.h"
#include <stack>

int Solution::evalRPN(vector<string>& tokens) {
    stack<int> nums;
    for (string& token: tokens) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int num1, num2;
            num2 = nums.top();
            nums.pop();
            num1 = nums.top();
            nums.pop();
            if (token == "+") {
                nums.push(num1 + num2);
            } else if (token == "-") {
                nums.push(num1 - num2);
            } else if (token == "*") {
                nums.push(num1 * num2);
            } else if (token == "/") {
                nums.push(int(num1 / num2));
            }
        } else {
            nums.push(stoi(token));
        }
    }
    return nums.top();
}
