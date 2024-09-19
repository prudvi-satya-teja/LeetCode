class Solution {
public:
    int search(vector<int>& arr, int target) {
        int n = arr.size();

        int low = 0;
        int high = n-1;

        while(low <= high) {

            int mid = (low + high) / 2;
            if(arr[mid] == target) {
                return mid;
            }
            else if(arr[mid] >= arr[low] && arr[mid] >  arr[high]) {   // first 
                // case1 : 
                if(target >= arr[low] && target < arr[mid]) {
                    high = mid-1;  
                } 
                else {
                    low = mid+1;
                }
               
            }
            else  {   // second    m,    , , ,, , 
                // case2 : 
                if(target > arr[mid] && target <= arr[high]) {
                    low = mid + 1;
                }
                else {
                    high = mid -1;
                }
            }
        }
        return -1;
        
    }
};