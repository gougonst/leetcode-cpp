#include "find_all_anagrams_in_a_string.h"
#include <unordered_map>

// Brute force
vector<int> Solution::findAnagrams1(string s, string p) {
    if (p.length() > s.length())
        return {};

    unordered_map<char, int> anagramCount;
    for (auto& c: p)
        anagramCount[c]++;

    vector<int> heads;
    for (int i = 0; i <= s.length() - p.length(); i++) {
        unordered_map<char, int> anagramCountCopy = anagramCount;
        for (int j = 0; j < p.length(); j++) {
            anagramCountCopy[s[i + j]]--;
        }
        int flag = true;
        for (auto& letterCount: anagramCountCopy) {
            if (letterCount.second != 0) {
                flag = false;
                break;
            }
        }
        if (flag)
            heads.push_back(i);
    }
    return heads;
}

vector<int> Solution::findAnagrams2(string s, string p) {
    int stringLength = s.length();
    int anagramLength = p.length();

    if (anagramLength > stringLength)
        return {};

    vector<int> anagramCount(26, 0);
    for (auto& c: p)
        anagramCount[c - 'a']++;

    vector<int> candidateCount(26, 0);
    for (int i = 0; i < anagramLength - 1; i++)
        candidateCount[s[i] - 'a']++;

    vector<int> heads;
    for (int i = anagramLength - 1; i < stringLength; i++) {
        candidateCount[s[i] - 'a']++;
        int headIdx = i - (anagramLength - 1);
        if (candidateCount == anagramCount)
            heads.push_back(headIdx);
        candidateCount[s[headIdx] - 'a']--;
    }
    return heads;
