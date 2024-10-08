class Solution {
public:
    int hammingDistance(int x, int y) {
         x = x ^ y;
        int cnt = 0;
        while(x > 0) {
            int r1 = x & 1;
            if(r1 == 1) cnt++;
            x = x>>1;
        }

        return cnt;
        
    }
};