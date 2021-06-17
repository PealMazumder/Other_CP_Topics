//Problem Link: https://codeforces.com/contest/975/problem/C
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
    ll n, q, i, j, x;
    cin>>n>>q;
    vector<ll> a, b;
    ll sm = 0;
    for(i = 0; i < n; i++)
    {
        cin>>x;
        sm += x;
        a.pb(sm);
    }
    sm = 0;
    for(i = 0; i < q; i++)
    {
        cin>>x;
        sm += x;
        auto id = lower_bound(all(a), sm);
        if(id == a.end())
        {
            sm = 0;
            cout<<n<<nl;
            continue;
        }
        auto idx = id - a.begin();

        if(a[idx] > sm)
            cout<<n - idx<<nl;
        else if(n - idx -1 == 0)
            cout<<n<<nl, sm = 0;
        else cout<<n - idx -1<<nl;
    }
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
