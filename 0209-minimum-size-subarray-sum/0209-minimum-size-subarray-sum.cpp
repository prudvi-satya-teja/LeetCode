class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int si = 0;
        int mn = INT_MAX;

        int sum = 0;
        for(int i=0; i<nums.size(); i++) {
            int ele = nums[i];
            sum += ele;
            while(sum >= target) {
                mn = min(mn, i - si +1);
                sum -= nums[si];
                si++;
            }
        }

        return mn == INT_MAX ? 0 : mn;
    }
};