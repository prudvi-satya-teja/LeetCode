class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {

        unordered_map<char,int> mp;

        for(int i=0; i<allowed.size(); i++) {
            mp[allowed[i]]++;
        }

        int count = 0;
        for(int i=0; i<words.size(); i++) {
            string str = words[i];
            for(int j=0; j<str.size(); j++) {
                char ch = str[j];
                if(mp.find(ch) == mp.end()) {
                    break;
                }
                if(j == str.size()-1) {
                    count++;
                }
            }
        }
        return count;
    }
};