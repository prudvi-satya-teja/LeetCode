class Solution {
public:
    long long dividePlayers(vector<int>& skill) {

        long long sum = accumulate(skill.begin(), skill.end(), 0LL);
         sum = sum / (skill.size() / 2);

         long long ans = 0;
         
         unordered_map<int,int> mp;
         for(int i=0; i<skill.size(); i++) {
            mp[skill[i]]++;
         }

         for(auto i: mp) {

            long long ele = i.first;
            long long req = sum - ele;

            if(mp.find(req) == mp.end()) return -1;

            if(ele == req) {

                if(mp[ele] % 2 == 0) {
                    long long onePro = ele * ele;
                    long long pairs = mp[ele] / 2;
                    if(pairs > 0) ans  += (pairs * onePro);
                    mp[ele] = 0; 
                } 
                else return -1;
            }
            else {
                if(mp[ele] == mp[req]) {
                    long long onePro = ele * req;
                    long long pairs = mp[ele];
                    if(pairs > 0 ) ans += (pairs * onePro);
                    mp[ele] = 0;
                    mp[req] = 0;
                }
                else {
                    return -1;
                }
            // cout<<i.first<<" "<<ans<<"\n";
         }
         }
         return ans;
    }
};