#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target);
private:
    int _search(vector<int>& nums, int target, int left, int right);
};
