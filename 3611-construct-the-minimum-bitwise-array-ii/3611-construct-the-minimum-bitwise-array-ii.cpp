class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {

        vector<int> v;
        for(int i=0; i<nums.size(); i++) {
            int ele = nums[i];

            if(ele == 2) {
                v.push_back(-1);
            }
            else {
                int temp = ele;
                int k = 0;
                int pos = -1;
                while(ele > 0) {
                    if(!(ele & 1)) {
                        pos = k-1;
                        break;
                    }
                    ele = ele>>1;
                    k++;
                }
                if(pos == -1) pos = k-1;
                v.push_back(temp & (~(1<<pos)));
                
            }
        }
        return v;
    }
};