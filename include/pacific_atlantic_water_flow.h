#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    const static int PACIFIC_OCEAN = 0;
    const static int ATLANTIC_OCEAN = 1;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights);
private:
    void _islandFlowToOcean(int r, int c, int ocean, int preHeight);
    vector<vector<int>> _heights;
    vector<vector<bool>> _visited;
    vector<vector<vector<bool>>> _flowMap;
    int _rows;
    int _cols;
};
