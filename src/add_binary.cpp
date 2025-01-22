#include <iostream>
#include <stack>
#include "add_binary.h"

string Solution::addBinary(string a, string b) {
    int aIdx = a.length() - 1;
    int bIdx = b.length() - 1;
    int carry = 0;

    string binary = "";
    while (aIdx >= 0 || bIdx >= 0 || carry) {
        if (aIdx >= 0) {
            carry += a[aIdx] - '0';
        }
        if (bIdx >= 0) {
            carry += b[bIdx] - '0';
        }
        binary = char('0' + (carry % 2)) + binary;
        carry /= 2;
        aIdx--;
        bIdx--;
    }
    return binary;
}
