#include <vector>
#include <string>
using namespace std;

struct TrieNode {
    bool isWord;
    TrieNode* children[26];
    TrieNode() {
        isWord = false;
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
    }
};

class Solution {
public:
    vector<string> topKFrequent1(vector<string>& words, int k);
    vector<string> topKFrequent2(vector<string>& words, int k);
    vector<string> topKFrequent3(vector<string>& words, int k);
private:
    int _k;
    void _addWord(TrieNode& root, const string& word);
    void _getWord(TrieNode& root, const string& prefix, vector<string>& res);
};
