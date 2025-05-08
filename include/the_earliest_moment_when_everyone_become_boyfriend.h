#include <vector>
using namespace std;

class UnionFind {
public:
    UnionFind(int n) : _n(n) {
        for (int i = 0; i < n; i++) {
            _root.push_back(i);
        }
        _rank = vector<int>(n, 1);
    }

    int find(int x) {
        if (x == _root[x])
            return x;
        return _root[x] = find(_root[x]);
    }

    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (_root[rootX] == _root[rootY]) {
                _root[rootX] = _root[rootY];
                _rank[rootY]++;
            }
            else if (_root[rootX] < _root[rootY]) {
                _root[rootX] = _root[rootY];
            }
            else {
                _root[rootY] = _root[rootX];
            }
            _n--;
        }
    }

    int getNumberOfGraph() {
        return _n;
    }
private:
    vector<int> _root;
    vector<int> _rank;
    int _n;
};

class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int n);
};
