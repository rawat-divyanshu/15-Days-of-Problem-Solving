// Problem Link : https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.length();
        if(n == 1) return {0};
        
        int totalMoves = 0;
        int totalBoxes = 0;
        
        for(int i = 0; i < n; ++i) {
            if(boxes[i] == '1') {
                totalMoves += i;
                ++totalBoxes;
            }
        }
        
        int l = 0;
        int r = totalBoxes;
        
        int current = totalMoves;
        
        vector<int> res;
        
        for(int i = 0; i < n; ++i) {
            res.push_back(current);
            if(boxes[i] == '1') {
                ++l; --r;
            }
            
            current += l;
            current -= r;
        }
        return res;        
    }
};