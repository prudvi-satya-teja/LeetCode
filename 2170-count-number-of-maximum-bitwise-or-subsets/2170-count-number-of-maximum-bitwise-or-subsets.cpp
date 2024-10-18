class Solution {
public:
    int count = 0;
    set<vector<int>> st;

    void solve(vector<int>& nums, int n, int maxOr, int currOr, vector<int>& v) {
        if(currOr == maxOr) {
                st.insert(v);
        }

        if(n < 0)  {
            return;
        }
        
        v.push_back(n);
        solve(nums, n-1, maxOr, currOr | nums[n], v);
        v.pop_back();

        solve(nums, n-1, maxOr, currOr, v);

    }

    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;
        for(int i=0; i<nums.size(); i++) maxOr |= nums[i];
        vector<int> v;
        solve(nums, nums.size()-1, maxOr, 0, v);
        return st.size();

    }
};