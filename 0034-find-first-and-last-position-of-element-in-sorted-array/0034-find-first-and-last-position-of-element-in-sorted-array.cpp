class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v;

        int n = nums.size();
        int low = 0;
        int high = n-1;
        int first = -1, last = -1;


        while(low <= high) {
            int mid = (low + high) / 2;

            if(nums[mid] == target) {
                first = mid;
                high = mid - 1;
            }
            else if(target < nums[mid]) {
                high = mid -1;
            }
            else {
                low = mid + 1;
            }
        }

        low = 0;
        high = n-1;

        while(low <= high) {
            int mid = (low + high) / 2;

            if(nums[mid] == target) {
                last = mid;
                low = mid + 1;
            }
            else if(target < nums[mid]) {
                high = mid -1;
            }
            else {
                low = mid + 1;
            }
        }

        v.push_back(first);
        v.push_back(last);
        return v;
    }
};