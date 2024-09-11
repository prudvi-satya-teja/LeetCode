class Solution {
public:
    int minBitFlips(int start, int goal) {
        bitset<32> a = start;
        bitset<32> b = goal;
        bitset<32> c = a ^ b;
        return c.count();

        
    }
};