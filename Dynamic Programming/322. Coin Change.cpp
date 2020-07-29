//Problem Link: https://leetcode.com/problems/coin-change/
class Solution {
	const int INF = 100000000;
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[amount + 1];
        int n = (int)coins.size();
        for(int i = 1; i <= amount; i++) dp[i] = INF;
        dp[0] = 0;
        for(int i = 1; i <= amount; i++)
        {
            if(dp[i] == INF)
            {
                int tm = INF;
                for(int j = 0; j<n; j++)
                {
                    if(coins[j] <= i)
                        tm = min(tm, 1 + dp[i - coins[j]]);
                }
                dp[i] = tm;
            }
        }
        if(dp[amount] == INF) return -1;
        return dp[amount];
    }
};
