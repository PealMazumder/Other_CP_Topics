//Problem Link: https://codeforces.com/contest/1520/problem/E
#include<bits/stdc++.h>
#define nl "\n"
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define    all(p) p.begin(),p.end()
using namespace std;
int casino = 0;
void solve()
{
    ll n, i, j, k;
    string s;
    cin>>n>>s;
    ll ans = 0;
    ll l = 0, r = n-1;
    ll lcnt = 0, rcnt = 0;
    if(s[0] == '*') lcnt++;
    if(s[r] == '*')rcnt++;
    while(l < r)
    {
        if(lcnt <= rcnt)
        {
            l++;
            if(s[l] == '*')
                lcnt++;
            else if(s[l] == '.')
                ans += lcnt;
        }

        else
        {
            r--;
            if(s[r] == '*')
                rcnt++;
            else if(s[r] == '.')
                ans += rcnt;
        }
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
 
