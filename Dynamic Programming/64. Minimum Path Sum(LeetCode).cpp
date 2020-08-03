class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = (int)grid.size();
        int m = (int)grid[0].size();
        int dp[n+1][m+1];
        
        for(int i = 0; i<=m; i++)
            dp[0][i] = INT_MAX;
        for(int i = 0; i<=n; i++)
                dp[i][0] = INT_MAX;
        dp[0][1] = dp[1][0] = 0;
        
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
              dp[i][j] = grid[i-1][j-1] + min(dp[i-1][j], dp[i][j-1]);
        }
        return dp[n][m];
    }
    
};