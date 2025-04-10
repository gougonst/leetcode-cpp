#include <vector>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word);
private:
    bool _dfs(pair<int, int> loc, int cur);
    vector<vector<char>> _board;
    vector<pair<int, int>> _directions;
    string _word;
    int _height;
    int _width;
};
