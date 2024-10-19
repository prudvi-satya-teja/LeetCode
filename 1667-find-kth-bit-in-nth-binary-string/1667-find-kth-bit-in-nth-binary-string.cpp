class Solution {
public:
    char findKthBit(int n, int k) {

        string str = "0";
        if(n == 1) return '0';

        for(int i=2; i<=n; i++) {
            string currStr = str;
            for(int i=0; i<=currStr.size(); i++) {
                if(currStr[i] == '0') currStr[i] = '1';
                else currStr[i] = '0';
            }
            reverse(currStr.begin(), currStr.end());
            str = str + "1" + currStr;
        }
        return str[k-1];
    }
};