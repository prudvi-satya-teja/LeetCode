class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = 0;
        for(int i=0; i<piles.size(); i++) {
            high = max(high, piles[i]);;
        }

        while(low <= high) {
            int mid = (low + high) >> 1;
            //cout<<mid<<" ";
            long long count = 0;
            for(int i=0; i<piles.size(); i++) {
                count+=(piles[i]/mid);
                if(piles[i]%mid!=0) count+=1;
            }
            if(count <= h) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};