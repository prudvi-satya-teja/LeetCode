class Solution {
public:
    int mySqrt(int x) {

        if(x == 0 || x == 1) return x;
        long long low =  0;
        long long high = x/2;
        long long ans = -1;
        while(low <= high) {
            long long mid = (low + high) >> 1;

            if((mid * mid) <= (long long) x) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return ans;
    }
};