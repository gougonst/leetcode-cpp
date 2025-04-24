#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct1(vector<int>& nums);
    int maxProduct2(vector<int>& nums);
private:
    int _maxNonZeroProduct(vector<int>& nums);
};
