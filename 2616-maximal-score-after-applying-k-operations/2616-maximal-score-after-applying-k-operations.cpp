class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long sum = 0;
        priority_queue<int> pq;
        for(int i=0; i<nums.size(); i++) {
            pq.push(nums[i]);
        }

        while(k--) {
            int top = pq.top();
            pq.pop();
            sum += top;
            
            pq.push(ceil(top/3.0));
            cout<<top<<" ";
        }

        return sum;
    }
};