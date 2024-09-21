class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int n = matrix.size();
        int m = matrix[0].size();
        int low = 0;
        int high = (n * m) -1;

        int mid = 0;

        while(low <= high) {
             mid = (low + high) >> 1;
            int r = mid / (m);
            int c = mid %( m);
            if(matrix[r][c] == target)  return true;
            else if(matrix[r][c] > target)   high = mid - 1;
            else  low = mid + 1;
        }

        return false;
    }
};