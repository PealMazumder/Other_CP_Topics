//Problem Link: https://leetcode.com/problems/maximum-erasure-value/
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int l = 0, r = 0;
        int n = (int)nums.size();
        unordered_map<int, bool> mp;
        int sum = 0, mx = 0;
        while(r < n)
        {
            if(mp[nums[r]] == true)
            {
                mx = max(sum, mx);
                while(true)
                {
                    if(nums[l] == nums[r])
                    {
                        l++;
                        break;
                    }
                    sum -= nums[l];
                    mp[nums[l]] = false;
                    l++;
                }
            }
            else
            {
                sum += nums[r];
                mp[nums[r]] = true;
            }
            r++;
        }
        mx = max(mx, sum);
        return mx;
    }
};
