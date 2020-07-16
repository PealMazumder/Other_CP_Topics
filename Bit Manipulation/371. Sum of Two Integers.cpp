class Solution {
public:
    int getSum(int x, int y) {
        int a = x ^ y;
        unsigned int c = x & y;
        while (true){
            if((a ^ (c << 1)) == a){
                break;
            }
            int temp = a;
            a = (a ^ (c << 1));
            c = temp & (c << 1);
        }
        return a;
    }
};
/*
class Solution {
public:
    int getSum(int a, int b) {
       return b == 0 ? a : getSum(a^b, (unsigned int)(a&b)<<1);
    }
};
*/
