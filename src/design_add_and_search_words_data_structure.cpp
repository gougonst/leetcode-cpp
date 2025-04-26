#include <queue>
#include "design_add_and_search_words_data_structure.h"

TrieNode::TrieNode() {
    isEnd = false;
    for (TrieNode*& child: children)
        child = nullptr;
}

WordDictionary::WordDictionary() {
    _trie = new TrieNode();
}

void WordDictionary::addWord(string word) {
    TrieNode* curNode = _trie;
    for (const char& c: word) {
        int cIdx = c - 'a';
        if (!curNode->children[cIdx]) {
            curNode->children[cIdx] = new TrieNode();
        }
        curNode = curNode->children[cIdx];
    }
    curNode->isEnd = true;
}

bool WordDictionary::search(string word) {
    queue<TrieNode*> searchq;
    searchq.push(_trie);
    for (const char& c: word) {
        int qSize = searchq.size();
        for (int i = 0; i < qSize; i++) {
            TrieNode* curNode = searchq.front();
            searchq.pop();
            if (!curNode) {
                continue;
            }

            if (c == '.') {
                for (TrieNode* node: curNode->children) {
                    searchq.push(node);
                }
            }
            else {
                searchq.push(curNode->children[c - 'a']);
            }
        }
    }
    while (!searchq.empty()) {
        TrieNode* node = searchq.front();
        searchq.pop();
        if (node && node->isEnd)
            return true;
    }
    return false;
}
