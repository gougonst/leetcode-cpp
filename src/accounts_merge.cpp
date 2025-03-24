#include "accounts_merge.h"
#include <unordered_map>
#include <unordered_set>

vector<vector<string>> Solution::accountsMerge(vector<vector<string>>& accounts) {
    unordered_map<string, vector<string>> graph;
    unordered_map<string, string> mailToName;
    for (int i = 0; i < accounts.size(); i++) {
        string name = accounts[i][0];
        string firstEmail = accounts[i][1];
        mailToName[firstEmail] = name;
        for (int j = 2; j < accounts[i].size(); j++) {
            string mail = accounts[i][j];
            graph[firstEmail].push_back(mail);
            graph[mail].push_back(firstEmail);
        }
    }

    vector<vector<string>> ans;
    unordered_set<string> visited;
    for (int i = 0; i < accounts.size(); i++) {
        vector<string> curResult;
        _dfs(curResult, graph, visited, accounts[i][1]);
        if (!curResult.empty()) {
            sort(curResult.begin(), curResult.end());
            curResult.insert(curResult.begin(), mailToName[accounts[i][1]]);
            ans.push_back(curResult);
        }
    }
    return ans;
}

void _dfs(
    vector<string> &curResult,
    unordered_map<string, vector<string>> &graph,
    unordered_set<string> &visited,
    string email
) {
    if (visited.count(email))
        return;

    visited.insert(email);
    curResult.push_back(email);
    for (int i = 0; i < graph[email].size(); i++) {
        _dfs(curResult, graph, visited, graph[email][i]);
    }
}
