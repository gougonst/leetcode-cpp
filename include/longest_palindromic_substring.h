#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s);
    string longestPalindrome1(string s);
private:
    bool _isPalindrome(string s);
    int _getPalindromeLen(string s, int l, int r)
};
