//Problem Link: https://www.hackerrank.com/challenges/the-power-sum/problem
#include<iostream>
#include<vector>
#include<unordered_map>
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
int Pow(int a, int b)
{
    int re = 1;
    while(b--)
        re *= a;
    return re;
}
void solve()
{
    int n, i, j, x;
    cin>>n>>x;
    vector<int> v, v2;
    for(i = 1; i<n; i++)
    {
        int tm = Pow(i, x);
        if(tm <= n)
            v.pb(tm);
        else break;
    }
//    for(auto xx : v)
//        cout<<xx<<" ";
//    cout<<nl;
    int vs = (sz(v)+1)/2;
    int vs2 = sz(v) - vs;
    int tot = 1 << vs;
    int ans = 0;
    for(int i = vs; i<sz(v); i++)
        v2.pb(v[i]);
    unordered_map<int, int> st;
    for(int mask = 0; mask<tot; mask++)
    {
        int sum = 0;
        bool ck = 0;
        for(int i = 0; i<vs; i++)
        {
            int tm = 1 << i;
            if((mask&tm) != 0)
                sum += v[i];
            if(sum > n) {ck = 1;break;}
        }
        if(!ck) st[sum]++;;

    }
    tot = 1 << vs2;
//    for(auto xx : st)
//        cout<<xx<<" ";
//    cout<<nl;
    for(int mask = 0; mask<tot; mask++)
    {
        int sum = 0;
        bool ck = 0;
        for(int i = 0; i<sz(v2); i++)
        {
            int tm = 1 << i;
            if((mask&tm) != 0)
                sum += v2[i];
            if(sum > n) {ck = 1;break;}
        }
        if(!ck)
        {
//            cout<<n-sum<<nl;
            if(st.find(n - sum) != st.end())
            {
                ans += st[n-sum];
            }
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
//    int t;
//    cin>>t;
//    while(t--)
        solve();
    return 0;
}
