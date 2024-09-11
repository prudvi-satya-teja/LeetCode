class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {

        unsigned long long ans = 0;
        int prev = 0;

        long long ele = nums[0];
        for(int i=1; i<nums.size(); i++) {
            if(nums[i] > ele) {
                long long curr = (i - prev) * ele;
                ele = nums[i];
                prev = i;
                ans += curr;
            }
            else if(i == nums.size()-1) {
                long long curr = (i - prev) * ele;
                ans += curr;
            }
        }
        return ans;
    }
};