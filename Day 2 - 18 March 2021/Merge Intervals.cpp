// Problem Link : https://leetcode.com/problems/merge-intervals/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        
        if(n <= 1) return intervals;
        
        sort(intervals.begin(), intervals.end(),
                  [](const vector<int>& a, const vector<int>& b) {
          return a[0] < b[0];
        });
        
        vector<vector<int>> res;
        
        int si = 0;
        int ei = 0;
        
        for(int i = 1; i < n; ++i) {
            if(intervals[i][0] > intervals[ei][1]) {
                res.push_back({intervals[si][0],intervals[ei][1]});
                si = ei = i;                
            } else {
                if(intervals[ei][1] < intervals[i][1]) {
                    ei = i;
                }
            }            
        }
        for(int i = ei + 1; i < n; ++i) {
            if(intervals[ei][1] < intervals[i][1]) {
                ei = i;
            }            
        }
        res.push_back({intervals[si][0],intervals[ei][1]});
        return res;
    }
};