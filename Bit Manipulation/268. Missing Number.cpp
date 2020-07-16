static const auto fast = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int len = nums.size();
        int ans = len;
        for(int i = 0; i<len; i++)
            ans ^= i^nums[i];
        return ans;
    }
};