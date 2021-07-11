//Problem Link: https://codeforces.com/contest/1547/problem/D
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
int reset(int N,int pos){return N= N & ~(1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}
bool isPowerOfTwo (ll x) {return x && (!(x&(x-1)));}
int Toggle(int N, int pos){return N ^= 1 << pos;}
void solve()
{
    int n, m, i, j, k, cnt = 0, sm = 0, a, b;
    cin>>n;
    int ar[n];
    for (i = 0; i<n; i++)
    {
        cin>>ar[i];
    }
    vector<int> ans;
    ans.pb(0);
    int pre = ar[0];
    for (i = 1; i<n; i++)
    {
        int cur = 0;
        for(j = 0; j<32; j++)
        {
            if(check(pre, j) && !check(ar[i], j))
            {
                cur = Toggle(cur, j);
            }
        }
        ans.pb(cur);
        pre = ar[i] ^ cur;
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
 
