// Problem Link : https://leetcode.com/problems/rotate-image/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        // Transposing the Matrix First
        for(int i = 0; i < rows; ++i) {
            for(int j = i+1; j < cols; ++j) {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        
        // Swapping the columns
        for(int i = 0, j = cols-1; i < j; ++i, --j) {
            for(int k = 0; k < rows; ++k) {
                swap(matrix[k][i],matrix[k][j]);
            }
        }
    }
};#include <iostream>
using namespace std;
int main() {
    cout<<"Hello World!";
}
