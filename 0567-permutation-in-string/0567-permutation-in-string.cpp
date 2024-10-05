class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m= s2.size();
        sort(s1.begin(), s1.end());
        for(int i=0; i<=m-n; i++) {
            string sub = s2.substr(i, i + n-i);
            sort(sub.begin(), sub.end());
            if(s1 == sub)  return true;
        }
        return false;
        
    }
};