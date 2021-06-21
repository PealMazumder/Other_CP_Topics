///Problem Link: https://codeforces.com/contest/123/problem/A
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
const int N = 1005;
ll n;
vector<ll> prime;
bool vis[N];
void sieve()
{
    for(ll i = 3; i*i<=N; i+=2)
    {
        if(!vis[i])
        {
            for(ll j = i*i; j<=N; j += 2*i)
                vis[j] = true;
        }
    }
    prime.push_back(2LL);
    for(ll i = 3; i<N; i += 2)
        if(!vis[i]) prime.push_back(i);
}
void solve()
{
    ll i, j;
    string s;
    cin>>s;
    unordered_map<char, ll> mp;
    for(i = 0; i<sz(s); i++)
        mp[s[i]]++;
    n = sz(s);
    sieve();
    ll last = 0;
    char ans[n+1];
    for(i = 1; i<=n; i++) ans[i] = '#';
    ll tot = 0;
    for(i = 0; i<sz(prime); i++)
        if(prime[i] *2 <= n) last = prime[i];
    char ch = '#';
    ll mx = 0;
    for(auto it : mp)
    {
        if(it.second >= mx)
        {
            ch = it.first;
            mx = it.second;
        }
    }
    if(ch == '#')
    {
        no;return;
    }
    for(i = 0; i<sz(prime) && prime[i] <= last; i++)
    {
        for(j = prime[i]; j<=n; j+= prime[i])
        {
            if(ans[j] == '#' && mp[ch] > 0)
            {
                ans[j] = ch;
                mp[ch]--;
            }
            else if(ans[j] == '#'&&mp[ch] == 0)
            {
                no;return;
            }
        }
    }
    for(i = 1; i<=n; i++)
    {
        if(ans[i] == '#')
        {
            bool ck = false;
            for(auto it : mp)
            {
                if(it.second != 0)
                {
                    ans[i] = it.first, ck = true;
                    mp[it.first]--;
                    break;
                }
            }
            if(!ck)
            {
                no;return;
            }
        }
    }

    yes;
    for(i = 1; i<=n; i++)
        cout<<ans[i];
    cout<<nl;

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
