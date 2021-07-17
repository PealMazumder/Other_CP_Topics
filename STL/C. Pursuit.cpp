//Problem Link: https://codeforces.com/contest/1530/problem/C
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
    ll n, m, i, j, k, cnt = 0, sm1 = 0, sm2 = 0;
    cin>>n;
    ll ar[n], br[n];
    for(i = 0; i<n; i++)
    {
        cin>>ar[i];
    }
    for(i = 0; i<n; i++)
    {
        cin>>br[i];

    }
    sort(ar, ar+n, [] (int a, int b){
         return a > b;
         });
    sort(br, br + n, [] (int a, int b){
         return a > b;
         });
    k = n - n/4;
    deque<ll> a, b;
    for(i = 0; i<k; i++)
        sm1 += ar[i], sm2 += br[i], a.push_back(ar[i]);

    if(sm1 >= sm2)
    {
        cout<<"0\n";
        return;
    }

    ll lb = k, prek = k, nn = n;
    ll ans = 0;
//    cout<<sm1<<" "<<sm2<<nl;
    while(sm1 < sm2)
    {

        nn++, ans++;
        k = nn - nn/4;
        if(prek < k)
        {
            if(lb < n)
                sm2 += br[lb], lb++;
            sm1 += 100;
            a.push_front(100);
        }
        else
        {
            m = a.back();
            a.pop_back();
            sm1 -= m;
            sm1 += 100;
            a.push_front(100);
        }
        prek = k;
//        cout<<sm1<<" "<<sm2<<nl;
    }
    cout<<ans<<nl;

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
