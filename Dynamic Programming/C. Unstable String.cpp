//Problem Link: http://codeforces.com/contest/1535/problem/C
#include<bits/stdc++.h>
#define nl "\n"
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define    all(p) p.begin(),p.end()
using namespace std;
int dp[200005][2];
string s;
ll NoOfBeautifulSub(int n, int i,  int p)
{
    if (i >= n || s[i] == '0' && p == 1 || s[i] == '1' && p == 0)
        return 0;
    if(dp[i][p] != -1) return dp[i][p];

    return dp[i][p] = NoOfBeautifulSub(n, i+1, p^1) + 1;
}
void solve()
{
    int n;
    cin>>s;
    ll ans = 0;
    n = sz(s);
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < n; i++)
    {
        ll a = -1, b = -1;
        a = NoOfBeautifulSub(n, i, 0);//expecting ith character is 0 or ?
        b = NoOfBeautifulSub(n, i, 1);//expecting ith character is 1 or ?
//        cout<<a<<" "<<b<<nl;
        ans += max(a, b);
    }
    cout<<ans<<nl;
}
int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}

