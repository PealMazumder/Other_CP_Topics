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
const ll mx = 1e6+7;
const ll N = 1e6 + 1;
vector<ll> primes;
bool vis[N];
void sieve()
{
	for(ll i = 3; i * i <= N; i += 2)
	{
		if(!vis[i])
		{
			for(ll j = i * i; j <= N; j += 2 * i)
				vis[j] = true;
		}
	}
	primes.push_back(2LL);
	for(ll i = 3; i < N; i += 2)
		if(!vis[i]) primes.push_back(i);
}
ll SOD(ll n)
{
    ll res = 1, sqrtn = sqrt(n);
    for(ll i = 0; i < primes.size() and primes[i] <= sqrtn; ++i)
    {
        if(n % primes[i] == 0)
        {
            ll tempSum=1, P = 1;
            while(n % primes[i] == 0)
            {
                n /= primes[i], P *= primes[i], tempSum += P;
            }
            sqrtn = sqrt(n), res *= tempSum;
        }
    }
  if(n != 1LL) res *= (n+1);
  return res;
}
void solve()
{
    ll n;
    cin>>n;
    cout<<SOD(n) - n<<nl;
}
int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(NULL);
    sieve();
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
