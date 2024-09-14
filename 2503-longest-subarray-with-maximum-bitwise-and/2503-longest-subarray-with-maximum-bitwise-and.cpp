class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        int mx = *max_element(nums.begin(), nums.end());

        int count = 0;
        int currcount = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == mx) {
                currcount++;
            }
            else {
                count = max(count, currcount);
                currcount = 0;
            }
        }
        count = max(count, currcount);
        return count;
        
    }
};