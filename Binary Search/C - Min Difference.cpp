//Problem Link: https://atcoder.jp/contests/abc212/tasks/abc212_c
#include<bits/stdc++.h>
#define         nl                  "\n"
#define         mod                 1000000007
#define         sz(c)               (int)c.size()
#define         pb                  push_back
#define         ff                  first
#define         ss                  second
#define         mkp                 make_pair
#define         ll                  long long
#define         pii                 pair<int, int>
#define         pll                 pair<ll, ll>
#define         vll                 vector<ll>
#define         vi                  vector<int>
#define         no                  cout<<"NO\n"
#define         yes                 cout<<"YES\n"
#define         one                 cout<<"1\n"
#define         mone                cout<<"-1\n"
#define         gcd(a, b)           __gcd(a, b)
#define         total_bit(a)        __builtin_popcount(a)
#define         lcm(a, b)           ((a)*((b)/gcd(a,b)))
#define         all(p)              p.begin(),p.end()
#define         mem(ar,val)         memset(ar, val, sizeof(ar))
#define         UNIQUE(a)           sort(all(a)); a.erase(unique(all(a)), a.end())
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const double pi = acos(-1.0);
const ll INF = 1000000000000000000;
const int N = 1e6+7;

void solve()
{
    ll n, m, i, x;
    cin>>n>>m;
    vector<ll> a, b;
    for (i = 0; i<n; i++)
    {
        cin>>x;
        a.pb(x);
    }
    for (i = 0; i<m; i++)
    {
        cin>>x;
        b.pb(x);
    }
    sort(all(b));
    ll ans = INT_MAX;
    for(i = 0; i<n; i++)
    {
        ll idx = lower_bound(all(b), a[i])- b.begin();

        if(idx < m && idx >= 0)
            ans = min(ans, abs(a[i] - b[idx]));
        if(idx - 1 >= 0)
            ans = min(ans, abs(a[i] - b[idx-1]));
    }
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
