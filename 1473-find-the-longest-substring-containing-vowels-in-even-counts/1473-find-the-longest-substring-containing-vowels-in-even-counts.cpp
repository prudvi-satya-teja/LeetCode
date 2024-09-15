class Solution {
public:
    int findTheLongestSubstring(string s) {

        vector<vector<int>> v(s.size()+1, vector<int> (5, 0));

        for( int i=0; i<s.size(); i++) {
            v[i+1][0] = v[i][0];
            v[i+1][1] = v[i][1];
            v[i+1][2] = v[i][2];
            v[i+1][3] = v[i][3];
            v[i+1][4] = v[i][4];
            if(s[i] == 'a') v[i+1][0] +=  1;
            else if(s[i] == 'e') v[i+1][1] +=  1;
            else if(s[i] == 'i') v[i+1][2] += 1;
            else if(s[i] == 'o') v[i+1][3] += 1;
            else if(s[i] == 'u') v[i+1][4] += 1;
        }

        int len  = 0;
        for(int i=1; i<=s.size(); i++) {
            for(int j=0; j<=i && i - j > len; j++) {
                int adiff = v[i][0] - v[j][0];
                int ediff = v[i][1] - v[j][1];
                int idiff = v[i][2] - v[j][2];
                int odiff = v[i][3] - v[j][3];
                int udiff = v[i][4] - v[j][4];

                // cout<<adiff<<" "<<ediff<<" "<<idiff<<" "<<odiff<<" "<<udiff<<endl;

                if(adiff % 2 == 0 && ediff % 2 == 0 && idiff % 2== 0 && odiff % 2== 0 &&udiff % 2 == 0) {
                    len = max(len, i - j);
                }
            }
        }

        return len;
    }
};