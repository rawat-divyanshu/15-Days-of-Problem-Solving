// Problem Link : https://leetcode.com/problems/first-missing-positive/

// BruteForce O(N^2)
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 1;
        
        int minPositive = 1;
        
        while(find(nums.begin(), nums.end(), minPositive) != nums.end()) {
            ++minPositive;
        }
        return minPositive;
    }
};

// Optimized O(N)
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 1;
        
        for(int i = 0; i < n; ++i) {
            while(nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i]-1]) {
                swap(nums[nums[i]-1],nums[i]);
            }
        }
        for(int i = 0; i < n; ++i) {
            if(nums[i] != i+1) {
                return i+1;
            }
        }
        return n+1;
    }
};