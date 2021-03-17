// Problem Link : https://leetcode.com/problems/subarray-sum-equals-k/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int,int> prefixSum {{0,1}};
        int sum = 0;
        for(auto num: nums) {
            sum += num;
            if(prefixSum.count(sum-k)) {
                ans += prefixSum[sum-k];
            }
            ++prefixSum[sum];
        }
        return ans;
    }
};