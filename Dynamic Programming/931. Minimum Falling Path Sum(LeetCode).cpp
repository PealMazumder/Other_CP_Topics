class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int n = (int)A.size();
        int dp[n+2][n+2];
        for(int i = 0; i<=n; i++)
            dp[i][0] = dp[i][n+1] = INT_MAX;
        for(int i = 0; i<n; i++)
            dp[n][i+1] = A[n-1][i];
        for(int i = n-1; i>=1; i--)
        {
           for(int j = 1; j<=n; j++)
           {
                int curr = A[i-1][j-1];
               dp[i][j] = A[i-1][j-1] + min(dp[i+1][j-1], min(dp[i+1][j], dp[i+1][j+1]));
           }
        }
        int ans = INT_MAX;
        for(int i = 1; i<=n; i++)
            ans = min(ans, dp[1][i]);
        return ans;
    }
};