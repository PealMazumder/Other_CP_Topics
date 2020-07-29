//Problem Link: https://leetcode.com/problems/coin-change/
class Solution {
public:
    
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        int dp[amount + 1];
        for(int i = 0; i<=amount; i++) dp[i] = INT_MAX;
        dp[0] = 0;
        for(int c : coins)
        {
            if(c <= amount)
                dp[c] = 1;
        }
        for(int i = 1; i<=amount; i++)
        {
            if(dp[i] == INT_MAX)
            {
                int tm = INT_MAX;
                for(int j = 0; j<coins.size(); j++)
                {
                    if(coins[j]>i) break;
                    else if(dp[i - coins[j]] != INT_MAX)
                        tm = min(tm, 1 + dp[i - coins[j]]);
                }
                dp[i] = tm;
            }
        }
        if(dp[amount] == INT_MAX) return -1;
        return dp[amount];
    }
};
