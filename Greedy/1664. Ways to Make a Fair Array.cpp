//https://leetcode.com/problems/ways-to-make-a-fair-array/
class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int RightEvenSum = 0, RightOddSum = 0;
        for(int i = 0; i<nums.size(); i++)
        {
            if(i&1) RightOddSum += nums[i];
            else RightEvenSum += nums[i];
        }
        
        int ans = 0, LeftEvenSum = 0, LeftOddSum = 0;
        for(int i = 0; i<nums.size(); i++)
        {
            if(i&1)
            {
                RightOddSum -= nums[i];
                if(RightOddSum + LeftEvenSum == RightEvenSum + LeftOddSum)
                    ans++;
                LeftOddSum += nums[i];
            }
            else
            {
                RightEvenSum -= nums[i];
                if(RightOddSum + LeftEvenSum == RightEvenSum + LeftOddSum)
                    ans++;
                LeftEvenSum += nums[i];
            }
        }
        return ans;
    }
};
