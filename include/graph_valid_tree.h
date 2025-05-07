#include <vector>
using namespace std;

class UnionFind {
public:
    UnionFind(int sz) : _nTree(sz) {
        for (int i = 0; i < sz; i++) {
            _root.push_back(i);
        }
        _rank = vector<int>(sz, 1);
    }

    int find(int x) {
        if (x == _root[x]) {
            return x;
        }
        return _root[x] = find(_root[x]);
    }

    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (_rank[rootX] == _rank[rootY]) {
                _root[rootX] = _root[rootY];
                _rank[rootY]++;
            }
            else if (_rank[rootX] < _rank[rootY]) {
                _root[rootX] = _root[rootY];
            }
            else {
                _root[rootY] = _root[rootX];
            }
            _nTree--;
        }
    }

    int getTreeNumber() {
        return _nTree;
    }
private:
    vector<int> _root;
    vector<int> _rank;
    int _nTree;
};

class Solution {
public:
    bool validTree1(int n, vector<vector<int>>& edges);
    bool validTree2(int n, vector<vector<int>>& edges);
};
