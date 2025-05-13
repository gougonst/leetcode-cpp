#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites);
private:
    bool _dfs(vector<vector<int>>& graph, int cur, int course);
};
