#include "string_to_integer.h"
#include <algorithm>

int Solution::myAtoi(string s) {
    int n = s.length();
    int result = 0;
    int sign = 1;

    int idx = 0;
    while (idx < n && s[idx] == ' ') {
        idx++;
    }

    if (idx < n && s[idx] == '-') {
        sign = -1;
        idx++;
    }
    else if (idx < n && s[idx] == '+') {
        idx++;
    }

    while (idx < n && isdigit(s[idx])) {
        int digit = s[idx] - '0';
        if (result > INT_MAX / 10 ||
            result == INT_MAX / 10 && digit > INT_MAX % 10) {
            return sign == 1 ? INT_MAX : INT_MIN;
        }
        result = result * 10 + digit;
        idx++;
    }
    return sign * result;
}
