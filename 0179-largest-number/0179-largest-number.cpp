class Solution {
public:

    string largestNumber(vector<int>& nums) {

        string ans = "";
        sort(nums.begin(), nums.end(), [](int n1 , int n2) {
            string str1  = to_string(n1);
            string str2 = to_string(n2);

            if(str1 + str2 > str2 + str1) {
                return true;
            }
            return false;
            }
        );

        for(int i=0; i<nums.size(); i++) {
            if(ans ==  "0" && nums[i] == 0) continue;
            ans+= to_string(nums[i]);
        }
        return ans;
    }
};