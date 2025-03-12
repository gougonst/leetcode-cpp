#include "implement_trie.h"

TrieNode::TrieNode() {
    isEnd = false;
    for (TrieNode*& child: children)
        child = nullptr;
}

Trie::Trie() {
    root = new TrieNode();
}

void Trie::insert(string word) {
    TrieNode* curNode = root;
    for (const char& c: word) {
        if (curNode->children[c - 'a'] == nullptr)
            curNode->children[c - 'a'] = new TrieNode();
        curNode = curNode->children[c - 'a'];
    }
    curNode->isEnd = true;
}

bool Trie::search(string word) {
    TrieNode* curNode = root;
    for (const char& c: word) {
        if (curNode->children[c - 'a'] == nullptr)
            return false;
        curNode = curNode->children[c - 'a'];
    }
    return curNode->isEnd;
}

bool Trie::startsWith(string prefix) {
    TrieNode* curNode = root;
    for (const char& c: prefix) {
        if (curNode->children[c - 'a'] == nullptr)
            return false;
        curNode = curNode->children[c - 'a'];
    }
    return true;
}
