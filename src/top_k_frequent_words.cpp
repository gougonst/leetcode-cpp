#include "top_k_frequent_words.h"
#include <unordered_map>
#include <queue>
#define pis pair<int,string>

// TC:
vector<string> Solution::topKFrequent1(vector<string>& words, int k) {
    unordered_map<string, int> wordFrequent;
    for (auto& word: words) {
        wordFrequent[word]++;
    }

    auto cmp = [] (const auto& lhs, const auto& rhs) {
        if (lhs.second == rhs.second) {
            return lhs.first < rhs.first;
        }
        return lhs.second > rhs.second;
    };
    vector<pair<string, int>> sortWordFrequent;
    for (auto& word: wordFrequent) {
        sortWordFrequent.push_back({word.first, word.second});
    }
    sort(sortWordFrequent.begin(), sortWordFrequent.end(), cmp);

    vector<string> ans;
    for (int i = 0; i < k; i++) {
        ans.push_back(sortWordFrequent[i].first);
    }
    return ans;
}

vector<string> Solution::topKFrequent2(vector<string>& words, int k) {
    unordered_map<string, int> wordFrequent;
    for (auto& word: words) {
        wordFrequent[word]++;
    }

    auto cmp = [] (const pis& lhs, const pis& rhs) {
        if (lhs.first == rhs.first)
            return lhs.second < rhs.second;
        return lhs.first > rhs.first;
    };
    priority_queue<pis, vector<pis>, decltype(cmp)> topKWords(cmp);
    for (auto& word: wordFrequent) {
        topKWords.push({word.second, word.first});
        if (topKWords.size() > k) {
            topKWords.pop();
        }
    }

    vector<string> ans;
    while (!topKWords.empty()) {
        ans.push_back(topKWords.top().second);
        topKWords.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

vector<string> Solution::topKFrequent2(vector<string>& words, int k) {
    unordered_map<string, int> wordFrequent;
    for (auto& word: words) {
        wordFrequent[word]++;
    }

    auto cmp = [] (const pis& lhs, const pis& rhs) {
        if (lhs.first == rhs.first)
            return lhs.second < rhs.second;
        return lhs.first > rhs.first;
    };
    priority_queue<pis, vector<pis>, decltype(cmp)> topKWords(cmp);
    for (auto& word: wordFrequent) {
        topKWords.push({word.second, word.first});
        if (topKWords.size() > k) {
            topKWords.pop();
        }
    }

    vector<string> ans;
    while (!topKWords.empty()) {
        ans.push_back(topKWords.top().second);
        topKWords.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

void Solution::_addWord(TrieNode& root, const string& word) {
    TrieNode* node = &root;

    for (auto& c: word) {
        if (node->children[c - 'a'] == nullptr)
            node->children[c - 'a'] = new TrieNode();
        node = node->children[c - 'a'];
    }
    node->isWord = true;
}

void Solution::_getWord(TrieNode& root, const string& prefix, vector<string>& ans) {
    if (_k == 0)
        return;
    if (root.isWord) {
        _k--;
        ans.push_back(prefix);
    }
    for (int i = 0; i < 26; i++) {
        if (root.children[i] == nullptr)
            continue;
        _getWord(*root.children[i], prefix + (char)('a' + i), ans);
    }
}

vector<string> Solution::topKFrequent3(vector<string>& words, int k) {
    _k = k;

    unordered_map<string, int> wordFrequent;
    for (auto& word: words) {
        wordFrequent[word]++;
    }

    vector<TrieNode> bucket(words.size() + 1, TrieNode());
    for (auto word: wordFrequent) {
        _addWord(bucket[word.second], word.first);
    }

    vector<string> ans;
    for (int i = words.size(); i > 0; i--) {
        _getWord(bucket[i], "", ans);
    }
    return ans;
}
