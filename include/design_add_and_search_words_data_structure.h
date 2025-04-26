#include <string>
using namespace std;

// O(n + k^26)
class TrieNode {
public:
    TrieNode();
    bool isEnd;
    TrieNode* children[26];
};

class WordDictionary {
public:
    WordDictionary();
    void addWord(string word);
    bool search(string word);
private:
    TrieNode* _trie;
};
