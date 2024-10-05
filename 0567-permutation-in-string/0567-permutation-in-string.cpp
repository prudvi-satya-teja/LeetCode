class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m= s2.size();
        
        vector<int> v(26, 0);
        for(int i=0; i<n; i++) {
            int  ch = s1[i] - 'a';
            v[ch]++;
        }

        for(int i=0; i<m; i++) {
            int ch = s2[i] - 'a';
            if(i < n-1) {
                v[ch]--;
            }
            else {
                v[ch]--;
                for(int j=0; j<26; j++) {
                    if(v[j] == 0 && j == 25) {
                        return true;
                    }
                    else if(v[j] != 0) break;
                }

                int prev = s2[i-n+1] - 'a';
                v[prev]++;
            }
        }
        return false;
        
    }
};