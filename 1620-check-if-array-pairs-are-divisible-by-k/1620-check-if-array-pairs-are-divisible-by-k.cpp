class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        for(int i=0; i<arr.size(); i++) {
            int ele = arr[i] % k;
            if(ele < 0) {
                ele = k + ele;
            }
            mp[ele]++;
        }

        for(auto i: mp) {
            cout<<i.first<<" "<<i.second<<"\n";
                if(i.first == 0) {
                    if(i.second % 2 != 0) {
                        return false;
                    }
                }
                else {
                    
                    int a = i.second;
                    int b = k - i.first;
                     if(mp.find(b) != mp.end()) {
                        b = mp[b];
                    }
                    if( a != b) {
                        return false;
                    }

                }

               
        }
        return true;
        
    }
};