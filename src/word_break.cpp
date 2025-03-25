#include "word_break.h"
#include <unordered_map>
#include <queue>

// Trie solution cannot handle this type of answer
// s = abcd
// dict = ["a", "abc", "b", "cd"]
TrieNode::TrieNode() : TrieNode('\0') {}

TrieNode::TrieNode(char _c) {
    c = _c;
    childrens = {};
    isEnd = false;
}

void TrieNode::addChild(TrieNode *_child) {
    childrens[_child->c] = _child;
}

bool Solution::wordBreak1(string s, vector<string>& wordDict) {
    TrieNode *dict = new TrieNode();
    for (auto &word: wordDict) {
        TrieNode *cur = dict;
        for (auto &c: word) {
            cur->addChild(new TrieNode(c));
            cur = cur->childrens[c];
        }
        cur->isEnd = true;
    }

    TrieNode *cur = dict;
    for (auto &c: s) {
        if (!cur->childrens.count(c)) {
            return false;
        }
        cur = cur->childrens[c];
        if (cur->isEnd) {
            cur = dict;
        }
    }
    return true;
}

// BFS
bool Solution::wordBreak2(string s, vector<string>& wordDict) {
    vector<int> seen(s.length() + 1, false);
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int start = q.front();
        q.pop();
        for (auto &word: wordDict) {
            int end = start + word.length();
            if (seen[end]) {
                continue;
            }
            string paring = s.substr(start, word.length());
            if (paring == word) {
                q.push(end);
                seen[end] = true;
                if (end == s.length())
                    return true;
            }
        }
    }
    return false;
}
