#include <vector>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums);
private:
    bool _dfs(vector<int>& nums, int n, int totalSum);
};
