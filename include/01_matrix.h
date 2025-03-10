#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat);
private:
    vector<vector<int>> _updateMatrix(vector<vector<int>>& mat, int i, int j);
};
