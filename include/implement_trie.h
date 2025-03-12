#include <vector>
using namespace std;

class TrieNode {
public:
    TrieNode();
    bool isEnd;
    TrieNode* children[26];
};

class Trie {
public:
    TrieNode* root;
    Trie();
    void insert(string word);
    bool search(string word);
    bool startsWith(string prefix);
};
