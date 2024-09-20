class Solution {
public:
    int findMin(vector<int>& arr) {

        int n = arr.size();
        int low = 0;
        int high = n-1;
        int mid = 0;

        if(arr[low] < arr[high]) return arr[low];        
        while(low <= high) {
            mid = (low + high) / 2;

            if(mid > 0 && arr[mid] < arr[mid-1]) {
                return arr[mid];
            }
            else if( arr[mid] > arr[high] && arr[mid] > arr[low]) { 
                low = mid + 1;
            }
            else  {
                high = mid  - 1;
            }
        }
        return arr[(mid+1) %  n];
    }
};