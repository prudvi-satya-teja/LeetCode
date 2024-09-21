class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int n = matrix[0].size()-1;
        int m = 0;

        while(n >=0 && m < matrix.size()) {
           
            int ele = matrix[m][n];
            if(ele == target) return true;
            else if(ele > target) n--;
            else if(ele < target) m++;
        }
        return false;
    }
};