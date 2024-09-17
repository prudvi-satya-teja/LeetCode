class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int n = matrix.size();
        int m = matrix[0].size();

        int idx1 = 0,  idx2 = m-1;

        while(idx1 < n && idx2 >= 0) {
            int val = matrix[idx1][idx2];
            if(val == target) {
                return true;
            }
            else if(val < target) {
                idx1++;
            }
            else {
                idx2--;
            }
        }
        return false;


        
    }
};