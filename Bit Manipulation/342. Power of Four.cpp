class Solution {
public:
    bool isPowerOfFour(int num) {
        int cnt = 0;
        if(num<=0||num & (num-1)) return false;
        while(num>0)
        {
            cnt++;
            num >>= 1;
        }
        if(cnt&1) return true;
        return false;
    }
};

/*Or

class Solution {
public:
    bool isPowerOfFour(int num) {
        return(num>0 &&!(num & (num-1))&& !(0xAAAAAAAA & num));
    }
};
0xAAAAAAAA is 10101010101010101010101010101010
*/