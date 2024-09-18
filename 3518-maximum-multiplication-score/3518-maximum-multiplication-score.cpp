class Solution {
public:

    long long solve(vector<int>& a, vector<int>& b, vector<vector<long long>>& dp, int n, int m) {
        if(m < 0) {
            return 0;
        }

        if(n < 0) {
            return -5000000000;
        }
        

        if(dp[m][n] != -1) {
            return dp[m][n];
        }
        
        // pick
        long long c = a[m];
        long long d = b[n];
        long long pick  = (c * d) + (solve(a, b, dp, n-1, m-1));
        // not pick
        long long notpick = solve(a, b, dp, n-1, m);

        return dp[m][n] = max(pick, notpick);
    }

    
    long long maxScore(vector<int>& a, vector<int>& b) {

        long long ans = 0;

        int m = a.size();
        int n = b.size();
        // vector<vector<long long>> dp(m+1, vector<long long> (n+1, -1));
        // return solve(a, b, dp, n-1, m-1);

        vector<vector<long long>> dp(m+1, vector<long long> (n+1, -500000000000));

        for(int i=0; i<n+1; i++) {
            dp[0][i] = 0;
        }

        

        for(int i=1; i<=m; i++) { 
          long long c = a[i-1];
            for(int j=i; j<=n; j++) { 
               long long d = b[j-1];
                long long pick = (c * d) + (dp[i-1][j-1]);
                long long notpick = dp[i][j-1];
                dp[i][j] = max(pick, notpick);
            }
        }

        return dp[m][n];
    }
};