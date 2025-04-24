#include "group_anagrams.h"
#include <unordered_map>

// O(NKlogK)
vector<vector<string>> Solution::groupAnagrams1(vector<string>& strs) {
    unordered_map<string, vector<string>> ansMap;

    for (auto& str: strs) {
        string sortStr = str;
        sort(sortStr.begin(), sortStr.end());
        ansMap[sortStr].push_back(str);
    }

    vector<vector<string>> ans;
    for (auto& group: ansMap) {
        ans.push_back(group.second);
    }
    return ans;
}

// It can use counting sort to enhance, O(NK)
vector<vector<string>> Solution::groupAnagrams2(vector<string>& strs) {
    unordered_map<string, vector<string>> ansMap;

    for (auto& str: strs) {
        string sortStr = _countingSort(str);
        ansMap[sortStr].push_back(str);
    }

    vector<vector<string>> ans;
    for (auto& group: ansMap) {
        ans.push_back(group.second);
    }
    return ans;
}

string Solution::_countingSort(string& str) {
    int counting[26] = {0};
    for (auto& c: str) {
        counting[c - 'a']++;
    }
    string sortStr = "";
    for (int i = 0; i < 26; i++) {
        sortStr += string(counting[i], 'a' + i);
    }
    return sortStr;
}
