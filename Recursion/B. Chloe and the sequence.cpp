///Problem Link: https://codeforces.com/contest/743/problem/B
#include<bits/stdc++.h>
#define nl "\n"
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define    all(p) p.begin(),p.end()
using namespace std;
int casino = 0;
ll fun(ll n, ll k)
{
    ll mid = (1LL << (n - 1LL));
    if(mid == k) return n;
    else if(k > mid) return fun(n - 1, k - mid);
    else return fun(n-1, k);
}
//38 137438953472
void solve()
{
    ll n, k;
    cin>>n>>k;
    ll ans = fun(n, k);
    cout<<ans<<nl;
}
int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(NULL);
//    int t;
//    cin>>t;
//    while(t--)
        solve();
    return 0;
}
