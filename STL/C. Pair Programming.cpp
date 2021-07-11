//Problem Link: https://codeforces.com/contest/1547/problem/C
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
#define         pv(v)               for(auto it : v) cout<< it <<" "; nl;
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
    ll n, m, i, j, k, cnt = 0, sm = 0, a, b;
    cin>>k>>n>>m;
    queue<ll> mo, po;
    for(i = 0; i<n; i++)
    {
        cin>>a;
        mo.push(a);
    }
    for(i = 0; i<m; i++)
    {
        cin>>a;
        po.push(a);
    }
    vector<ll> ans;
    while(true)
    {
        if(mo.empty() && po.empty()) break;
        if(mo.empty()) a = INT_MAX; else a = mo.front();
        if(po.empty()) b = INT_MAX; else b = po.front();

        if(min(a, b) > k)
        {
            mone;
            return;
        }
        if(a == 0)
        {
            ans.push_back(a);
            mo.pop();
            k++;
            continue;
        }
        if(b == 0)
        {
            ans.push_back(b);
            po.pop();
            k++;
            continue;
        }
        else
        {
            ans.push_back(min(a, b));
            if(a < b)
                mo.pop();
            else po.pop();
            continue;
        }
    }
    for(auto it : ans)
        cout<<it<<" ";
    cout<<nl;

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

