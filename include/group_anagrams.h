#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams1(vector<string>& strs);
    vector<vector<string>> groupAnagrams2(vector<string>& strs);
private:
    string _countingSort(string& str);
};
