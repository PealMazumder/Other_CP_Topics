#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod = 1000000007;
const int mx = 1000005;
//ll dp[mx];
//ll go(int n)
//{
//    if(n < 1) return 1;
//    if(dp[n] != 0) return dp[n];
//    int sm = 0;
//    for(int i = 1; i <= min(6, n); i++)
//    {
//        sm += go(n - i);
//        sm %= mod;
//    }
//    return dp[n] = sm;
//}

ll dp[mx + 1];
int main()
{
    int n;
    cin >> n;
//    cout<<go(n)<<"\n";
    dp[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= min(6, i); j++)
            dp[i] += dp[i - j], dp[i] %= mod;

    }
    cout<<dp[n]<<"\n";
    return 0;
}
