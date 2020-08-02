class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int x : nums)
            sum += x;
        if(sum & 1) return false;
       sum /= 2;
        bool dp[sum + 1];
        for(int i = 1; i<=sum; i++) dp[i] = false;
        dp[0] = true;
        for(int i = 0; i<nums.size(); i++)
        {
            for(int j = sum; j>=nums[i]; j--)
            {
                int need = j - nums[i];
                if(dp[j] || dp[need] == false)
                    continue;
                else dp[j] = true;
            }
        }
        
        if(dp[sum] == true)
            return true;
        return false;
    }
};