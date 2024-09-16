class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(), timePoints.end());
        int n = timePoints.size();

        int mn = INT_MAX;

        for(int i=0; i<n; i++) {
            string str1 = timePoints[i];
            string str2 = timePoints[(i+1)% n];
            if(i == n-1) {
                str1 = timePoints[(i+1)% n];
                str2 = timePoints[i];
            }

           
            int hour1 = (str1[0] - '0')* 10 + (str1[1]-'0');
            int hour2 = (str2[0] - '0')* 10 + (str2[1]-'0');
            int min1 = (str1[3] - '0')* 10 + (str1[4]-'0');
            int min2 = (str2[3] - '0')* 10 + (str2[4]-'0');
             // first diff
            int currdiff = min2 - min1 + (hour2 - hour1) * 60;
            mn = min(mn, abs(currdiff));
            // second diff
            int diff = (24 - hour2 -1) * 60 + 60 - min2  + min1 + hour1 * 60;
            mn  = min(mn, abs(diff));
        }
        return mn;
    }
};