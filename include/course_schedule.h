#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites);
private:
    bool isCyclic(int currentChild,
                  unordered_map<int, vector<int>>& ancients,
                  unordered_set<int>& visited);
};
