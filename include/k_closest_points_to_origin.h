#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k);
private:
    int _euclidien_distance(vector<int> &point);
};
