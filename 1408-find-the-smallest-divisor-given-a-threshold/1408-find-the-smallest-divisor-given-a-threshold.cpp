class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
    
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());


        while(low <= high) {
            int mid = (low + high) >> 1;

            int ans = 0;
            for(int i=0; i<nums.size(); i++) {
                ans += ceil(nums[i] / float(mid));
            }

            if(ans > threshold) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return low;
    }
};