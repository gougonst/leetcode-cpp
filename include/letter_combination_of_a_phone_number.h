#include <vector>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits);
private:
    void _buildCombinations(vector<string>& combinations,
                            string& digits,
                            unordered_map<char, string>& mapping,
                            string combination,
                            int depth);
};
