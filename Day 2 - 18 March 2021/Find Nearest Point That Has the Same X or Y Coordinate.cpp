// Problem Link : https://leetcode.com/problems/find-nearest-point-that-has-the-same-x-or-y-coordinate/

class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int ans = -1;
        int dis = INT_MAX;
        
        for(int i = 0; i < points.size(); ++i) {
            if(points[i][0] == x || points[i][1] == y) {
                int tempDis = abs(x - points[i][0]) + abs(y - points[i][1]);
                if(tempDis < dis) {
                    dis = tempDis;
                    ans = i;
                }
            }
        }
        return ans;
    }
};