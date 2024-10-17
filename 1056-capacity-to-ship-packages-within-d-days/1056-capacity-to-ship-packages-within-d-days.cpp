class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {

        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);


        while(low <= high) {
            int mid = (low + high) >> 1;
            int count = 0;
            int sum = 0;

            for(int i=0; i<weights.size(); i++) {
                sum += weights[i];

                if(sum == mid) {
                    count++;
                    sum = 0;
                }
                else if(sum > mid) {
                    count++;
                    sum = weights[i];
                }

                if(i == weights.size()-1 && sum > 0) {
                    count++;
                }
            }

            if(count > days) {
                low = mid + 1;
            }    
            else {
                high = mid -1;
            }

            
        }
        return low;
    }
};