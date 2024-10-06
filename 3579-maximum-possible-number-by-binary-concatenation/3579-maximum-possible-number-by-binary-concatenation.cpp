class Solution {
public:
    string solve(int num) {
        string str = "";
        while(num > 0) {
            int bit = num & 1;
            if(bit == 0) str+='0';
            else str+='1';

            num = num>>1;
        }
        return str;
    }
    long long solver(string str) {
        long long sum = 0;
        for(int i=0; i<str.size(); i++) {
            int ch = str[i] - '0';
            if(ch == 1) sum += pow(2, i);
        }
        return sum;
    }
    int maxGoodNumber(vector<int>& nums) {
        
        string s1 = solve(nums[0]);
        string s2 = solve(nums[1]);
        string s3 = solve(nums[2]);

        string s4 = s1 + s2 + s3;
        string s5 = s1 + s3 + s2;
        string s6 = s2 + s1 + s3;
        string s7 = s2 + s3 + s1;
        string s8 = s3 + s1 + s2;
        string s9 = s3 + s2 + s1; 
        long long sum = 0;
        sum = max(sum, solver(s4));
        sum = max(sum, solver(s5));
        sum = max(sum, solver(s6));
        sum = max(sum, solver(s7));
        sum = max(sum, solver(s8));
        sum = max(sum, solver(s9));

        
        return sum;
        
    }
};