class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        bool bit;
        uint32_t ans = 0;
        
        for(int i = 0; i<=31; i++)
        {
            bit = n & (1 << i);
            ans <<= 1;
            ans += bit;
        }
        return ans;   
    }
};