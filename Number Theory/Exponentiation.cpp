//Problem Link: https://cses.fi/problemset/task/1095
#include<bits/stdc++.h>
#define nl "\n"
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define    all(p) p.begin(),p.end()
using namespace std;
const int mod = 1e9 + 7;
int power(int a, int b)
{
    int res = 1;
    while(b)
    {
        if(b & 1) res = (res *1LL* a) % mod, b--;
        a = (a *1LL* a) % mod;
        b >>= 1;
    }
    return res;
}
void solve()
{
    int a, b;
    cin>>a>>b;
    cout<<power(a, b)<<nl;
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


