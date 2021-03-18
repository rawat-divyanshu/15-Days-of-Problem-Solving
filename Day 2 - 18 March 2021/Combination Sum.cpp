// Problem Link : https://leetcode.com/problems/combination-sum/

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> tmp;
        combinationSumHelper(candidates,target,tmp,0);
        return res;        
    }
    
    void combinationSumHelper(vector<int>& candidates, int sum, vector<int>& tmp, int i) {
        if(sum < 0) {
            return;
        }
        if(sum == 0) {
            res.push_back(tmp);
            return;
        }
        while(i < candidates.size() && sum >= candidates[i]) {
            tmp.push_back(candidates[i]);
            combinationSumHelper(candidates,sum-candidates[i],tmp,i);
            ++i;
            tmp.pop_back();
        }        
    }
};