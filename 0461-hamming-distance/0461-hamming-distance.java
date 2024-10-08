class Solution {
    public int hammingDistance(int x, int y) {
        
        int count = 0;

        while(x>0 || y>0) {
            int bit1 = x & 1;
            int bit2 = y & 1;
            if(bit1 != bit2) {
                count++;
            }

            x = x>>1;
            y = y>>1;

        }
        return count;
    }
}