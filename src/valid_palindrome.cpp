#include "valid_palindrome.h"

bool Solution::isPalindrome(string s) {
    int i = 0, j = s.length() - 1;
    while(i < j) {
        if (!isalnum(s[i])) {
            i++;
        } else if (!isalnum(s[j])) {
            j--;
        } else {
            if (tolower(s[i]) != tolower(s[j])) {
                return false;
            }
            i++;
            j--;
        }
    }
    return true;
}
