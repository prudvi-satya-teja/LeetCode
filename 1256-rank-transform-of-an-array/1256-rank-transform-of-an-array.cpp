class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int,int> mp;
        for(int i=0; i<arr.size(); i++) {
            mp[arr[i]]++;
        }

        int k=1;
        for(auto i: mp) {
            mp[i.first] = k;
            k++;
        }
        vector<int> v;
        for(int i=0; i<arr.size(); i++) {
            v.push_back(mp[arr[i]]);

        }
        return v;
    }
};