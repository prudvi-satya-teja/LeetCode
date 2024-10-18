class Solution {
public:
    int largestCombination(vector<int>& candidates) {

        int cnt = 0;

        for(int i=0; i<=31; i++) {
            int currCnt = 0;
            for(int j=0; j<candidates.size(); j++) {
                if((candidates[j] & (1 << i))) {
                    currCnt++;
                }
            }
            cnt = max(cnt,  currCnt);
            
        }   
        return cnt;
        
    }
};