//Problem Link: https://codeforces.com/contest/1549/problem/C
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
    ll n, m, q, i, j;
    cin>>n>>m;
    ll ans = n, a, b, type;
    map<ll, set<ll> > mp;
    for(i = 0; i<m; i++)
    {
        cin>>a>>b;
        if(a < b)
            swap(a, b);
        if(mp[b].empty())
            ans--;
        mp[b].insert(a);
    }
    cin>>q;
    while(q--)
    {
        cin>>type;
        if(type == 1)
        {
            cin>>a>>b;
            if(a < b)
                swap(a, b);
            if(mp[b].empty())
                ans--;
            mp[b].insert(a);
        }
        else if(type == 2)
        {
            cin>>a>>b;
            if(a < b)
                swap(a, b);
            mp[b].erase(a);
            if(mp[b].empty())
                ans++;
        }
        else cout<<ans<<nl;
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
