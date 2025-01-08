#include <unordered_map>
#include "ransom_note.h"

bool Solution::canConstruct(string ransomNote, string magazine) {
    if (magazine.length() < ransomNote.length()) {
        return false;
    }

    unordered_map<char, int> ransomNeeds;
    for (auto& c: ransomNote) {
        ransomNeeds[c] += 1;
    }
    for (auto& c: magazine) {
        if (ransomNeeds.count(c) > 0) {
            ransomNeeds[c] -= 1;
            if (ransomNeeds[c] == 0) {
                ransomNeeds.erase(c);
            }
            if (ransomNeeds.empty()) {
                return true;
            }
        }
    }
    return false;
}
