#include <vector>
#include <unordered_map>
using namespace std;

class TrieNode {
public:
    TrieNode();
    TrieNode(char _c);
    void addChild(TrieNode *_child);
    char c;
    unordered_map<char, TrieNode*> childrens;
    bool isEnd;
}

class Solution {
public:
    bool wordBreak1(string s, vector<string>& wordDict);
    bool wordBreak2(string s, vector<string>& wordDict);
};
