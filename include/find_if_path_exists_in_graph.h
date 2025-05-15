#include <vector>
using namespace std;

class UnionFind {
public:
    UnionFind(int n);
    int find(int x);
    void unionSet(int x, int y);
private:
    vector<int> _root;
    vector<int> _rank;
};

class Solution {
public:
    bool validPath1(int n, vector<vector<int>>& edges, int source, int destination);
    bool validPath2(int n, vector<vector<int>>& edges, int source, int destination);
};
