// Problem Link : https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

class Solution {
public:
    bool isPossibleToShip(vector<int> weights, int D, int minWeight) {
        
        int dayCount = 1;
        int weightShipped = 0;
        
        for(int i = 0; i < weights.size(); i++) {
            if(weights[i] > minWeight) {
                return false;
            }
            if(weightShipped + weights[i] > minWeight) {
                ++dayCount;
                weightShipped = weights[i];
                
                if(dayCount > D) {
                    return false;
                }
            } else {
                weightShipped += weights[i];
            }
        }
        return true;
    }
    
    int shipWithinDays(vector<int>& weights, int D) {
        int n = weights.size();
        int sum_of_all_weights = 0;
        
        for(int i = 0; i < n; i++) {
            sum_of_all_weights += weights[i];
        }
        int l = weights[n-1];
        int r = sum_of_all_weights;
        int ans = sum_of_all_weights;
        
        while(l <= r) {
            int mid = l + (r-l)/2;
            
            if(isPossibleToShip(weights, D, mid)) {
                ans = min(ans,mid);
                r = mid-1;
            } else {
                l = mid+1;
            }
        }        
        return ans;        
    }
};