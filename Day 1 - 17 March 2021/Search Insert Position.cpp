// Problem Link : https://leetcode.com/problems/search-insert-position/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0) return 0;
        int indexToBeInserted = 0;
        for(int i = 0; i < n; ++i) {
            if(nums[i] == target) {
                return i;
            }
            if(nums[i] > target) {
                return indexToBeInserted;
            }
            ++indexToBeInserted;
        }
        return indexToBeInserted;        
    }
};