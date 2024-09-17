class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> mp;
        string curr = "";
        for(int i=0; i<s1.size(); i++) {
            char ch = s1[i];
            if(ch == ' ') {
                mp[curr]++;
                curr = "";
            }
            else {
                curr += ch;
                if(i == s1.size()-1) {
                    mp[curr]++;
                    curr = "";
                }
            }
        }

         for(int i=0; i<s2.size(); i++) {
            char ch = s2[i];
            if(ch == ' ') {
                mp[curr]++;
                curr = "";
            }
            else {
                curr += ch;
                if(i == s2.size()-1) {
                    mp[curr]++;
                    curr = "";
                }
            }
        }

        vector<string> v;
        for(auto i: mp) {
            // cout<<i.first<<" ";
            if(i.second == 1) {
                v.push_back(i.first);
            }
        }
        return v;



        
    }
};