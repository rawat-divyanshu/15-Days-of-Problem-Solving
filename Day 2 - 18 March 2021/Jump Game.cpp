// Problem Link : https://leetcode.com/problems/jump-game/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1) return true;
        
        int x = n-1;
        
        for(int i = n-2; i >= 0; --i) {
            if(nums[i] + i >= x) {
                x = i;
            }
        }
        return x == 0;
    }
};