#include<bits/stdc++.h>
#define nl "\n"
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define    all(p) p.begin(),p.end()
using namespace std;
int casino = 0;
const ll N = 1e9 + 7;
void solve()
{
    ll n; cin>>n;
    vector<ll> a, b;
    for(ll i = 1; i<=100000; i++)
    {
        ll tm = (i*(i+1))/2;
        if(tm > n) break;
        a.pb(tm);
    }
    for(ll i = 0; i<sz(a); i++)
    {
        ll tm = n - a[i];
        auto id = lower_bound(all(a), tm) - a.begin();
        if(a[id] == tm)
        {
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";
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
