class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int  n = nums.size();
        int low = 0, high = nums.size()-1;
        int mid = 0;

        while(low <= high) {
            mid = (low + high) >> 1;
            // if mid is odd
            if(mid % 2 == 0) {
                if(mid > 0 && mid < n-1 && nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]) {
                    return nums[mid];
                }
                else if(mid < n-1 && nums[mid] != nums[mid+1]) {
                    high  = mid -1;
                }
                else {
                    low = mid + 1;
                }
            }
            else  { // if mid is even
                if(mid > 0 && mid < n-1 && nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]) {
                        return nums[mid];
                    }
                    else if(mid < n-1 && nums[mid] != nums[mid+1]) {
                        low = mid + 1;
                    }
                    else {
                        high = mid - 1;
                    }
            }

        }
        return nums[mid];
        
    }
};