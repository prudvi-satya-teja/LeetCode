class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v;

        int n = nums.size();
        int low = 0;
        int high = n-1;

        while(low <= high) {
            int mid = (low + high) / 2;

            if(nums[mid] == target) {
                // l
                if(mid == low) {
                    v.push_back(mid);
                    break;
                }
                else if(mid > low  && nums[mid-1] == target) {
                        high = mid-1;
                }
                else {
                    low = mid;
                }
            }
            else if(target < nums[mid]) {
                high = mid -1;
            }
            else {
                low = mid + 1;
            }
        }
        if(v.empty()) {
            v.push_back(-1);
        }

        low = 0;
        high = n-1;

        while(low <= high) {
            int mid = (low + high) / 2;

            if(nums[mid] == target) {
                // l
                if(mid == high) {
                    v.push_back(mid);
                    break;
                }
                else if(mid < high  && nums[mid+1] == target) {
                        low = mid + 1;
                }
                else {
                    high = mid;
                }
            }
            else if(target < nums[mid]) {
                high = mid -1;
            }
            else {
                low = mid + 1;
            }
        }

        if(v.size() == 1) v.push_back(-1);
        return v;
    }
};