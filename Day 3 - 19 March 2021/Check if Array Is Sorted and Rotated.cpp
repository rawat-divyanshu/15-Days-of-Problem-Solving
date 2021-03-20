// Problem Link : https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        
        if(n <= 2) return true;
        
        int idx = 1;
        
        while(idx < n && nums[idx] >= nums[idx-1]) {
            ++idx;
        }
        if(idx != n && nums[idx] > nums[0]) {
            return false;            
        }
        ++idx;
        while(idx < n) {
            if(nums[idx] < nums[idx-1] || nums[idx] > nums[0]) {
                return false;
            }
            ++idx;
        }
        return true;
    }
};