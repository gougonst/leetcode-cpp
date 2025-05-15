#include <vector>
using namespace std;

class Solution {
public:
    enum State {notVisited, isVisited, valid};
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination);
private:
    bool _dfs(unordered_map<int, vector<int>>& graph, vector<State>& visited, int source, int destination)
};
