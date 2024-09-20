class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int n = nums.size();

        if(n == 1) return 0;
        if(n > 1) {
            if(nums[0] > nums[1]) return 0;
            if(nums[n-1] > nums[n-2]) return n-1;
        }


        int low = 0;
        int high = nums.size()-1;

        while(low <= high) {
            int mid = (low + high) / 2;

            if(mid > 0 && mid < n-1 && nums[mid-1] < nums[mid] && nums[mid+1] < nums[mid]) {
                return mid;
            }
            else if(mid > 0 && nums[mid] < nums[mid-1]) {
                high = mid - 1;
            }
            else if(mid < n-1 && nums[mid] < nums[mid+1] ) {
                low = mid + 1;
            }

            else if(mid == 0 && mid + 1 != nums.size()-1) {
                if(nums[mid] > nums[1]) {
                    return 0;
                }
                else {
                    return 1;
                }
            }
            else if(mid == nums.size()-1) {
                if(nums[mid] > nums[mid-1]) {
                    return mid;
                }
                else {
                    return mid-1;
                }
            }
        }

        return 0;
        
    }
};