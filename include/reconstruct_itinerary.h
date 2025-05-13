#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets);
private:
    void _dfs(unordered_map<string, vector<string>>& graph, vector<string>& ans, string cur, int count, int n);
};
