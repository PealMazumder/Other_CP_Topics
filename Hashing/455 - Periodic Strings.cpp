//Problem Link: https://onlinejudge.org/external/4/455.pdf
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
#define ULL unsigned long long
const int N = 100;
const int M = 44444;
const ULL hs = 3797;

ULL F[N], H[N];
char in[N];
int n;
bool ck = 0;
void solve()
{
    if(ck)cout<<nl;
    ck = 1;
    string s;
    cin>>s;
    H[0] = 0; for(int i = 1; i <= sz(s); i++) H[i] = H[i - 1] * hs + s[i-1];
    int ans = 0;
    for(int i = 1; i<=sz(s); i++)
    {
        unordered_set<ULL> st;
        for(int j = 1; j<=sz(s); j += i)
        {
            ULL curr = H[j + i - 1] - H[j-1]*F[i];
            st.insert(curr);
        }
        if(sz(st) == 1) {ans = i; break;}
    }
    cout<<ans<<nl;
}
int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(NULL);
    F[0] = 1; for(int i = 1; i < N; i++) F[i] = F[i - 1] * hs;
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
