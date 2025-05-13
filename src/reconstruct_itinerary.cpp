#include "reconstruct_itinerary.h"
#include <unordered_map>
#include <unordered_set>

vector<string> Solution::findItinerary(vector<vector<string>>& tickets) {
    unordered_map<string, vector<string>> graph;
    for (auto& ticket: tickets)
        graph[ticket[0]].push_back(ticket[1]);

    // Sort here, so that we can use DFS from lower lexical to higher lexical
    for (auto& vertex: graph)
        sort(vertex.second.rbegin(), vertex.second.rend());

    int n = tickets.size();
    vector<string> ans;
    _dfs(graph, ans, "JFK");
    reverse(ans.begin(), ans.end());
    return ans;
}

void Solution::_dfs(unordered_map<string, vector<string>>& graph, vector<string>& ans, string cur) {
    while (!graph[cur].empty()) {
        string neighbor = graph[cur].back();
        graph[cur].pop_back();
        _dfs(graph, ans, neighbor);
    }
    ans.push_back(cur);
}
