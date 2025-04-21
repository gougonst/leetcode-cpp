#include <vector>
using namespace std;

class Solution {
public:
    int rob1(vector<int>& nums);
    int rob2(vector<int>& nums);
    int rob3(vector<int>& nums);
private:
    int _robForm(vector<int>& nums, vector<int>& memo, int i);
};
