#include <vector>
using namespace std;

class Solution {
public:
    int numIslands1(vector<vector<char>>& grid);
    int numIslands2(vector<vector<char>>& grid);
    int numIslands3(vector<vector<char>>& grid);
private:
    void _dfs(vector<vector<char>>& grid, int rows, int cols, int r, int c);
    void _bfs(vector<vector<char>>& grid, int rows, int cols, int r, int c);
};
