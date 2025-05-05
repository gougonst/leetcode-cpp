#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS1(vector<int>& nums);
    int lengthOfLIS2(vector<int>& nums);
    int lengthOfLIS3(vector<int>& nums);
private:
    int _binarySearch(vector<int>& smallestEndWithSubquence, int num);
};
