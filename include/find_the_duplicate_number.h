class Solution {
public:
    int findDuplicate(vector<int>& nums);
private:
    int _smaller_or_equal(vector<int>& nums, int cur);
};
