// Problem Link : https://leetcode.com/problems/combination-sum-ii/

class Solution {
public:
    set<vector<int>> resS;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> tmp;
        combinationSum2Helper(candidates,target,tmp,0);
        vector<vector<int>> res;
        copy(resS.begin(), resS.end(), back_inserter(res));
        return res;
    }
    
    void combinationSum2Helper(vector<int>& candidates, int sum, vector<int>& tmp, int i) {
        if(sum < 0) {
            return;
        }
        if(sum == 0) {
            resS.insert(tmp);
            return;
        }
        while(i < candidates.size() && sum >= candidates[i]) {
            tmp.push_back(candidates[i]);
            combinationSum2Helper(candidates,sum-candidates[i],tmp,i+1);
            ++i;
            tmp.pop_back();
        }
    }
};