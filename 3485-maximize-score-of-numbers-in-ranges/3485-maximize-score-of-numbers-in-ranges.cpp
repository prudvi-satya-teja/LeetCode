class Solution {
public:
    bool isValid(long long mid, vector<int>& start, long long d) {
        long long ele = start[0] + mid;
        bool ans = true;

        for(int i=1; i<start.size(); i++) {
            long long st = start[i];
            long long end = st + d;
            if(ele > end) {
                return false;
            }
            else {
                if(ele < st) {
                    ele = st;
                }
            }
            ele = ele + mid;
        }
        return ans;
    }
    int maxPossibleScore(vector<int>& start, int d) {
        sort(start.begin(), start.end());

        long long  low = 0;
        long long  high = start[start.size()-1] + d;
        long long  ans = 0;
        while(low <= high) {
            long long mid = (low + high) / 2;
            // cout<<mid<<endl;
            if(isValid(mid, start, d)) {
                ans = max(ans, mid);
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return ans;
    }
};