//Problem Link: https://codeforces.com/contest/1046/problem/C
#include<bits/stdc++.h>
#define		nl			"\n"
#define     	ss          		" "
#define		mod			1000000007
#define		sz(c)			(int)c.size()
#define		pb			push_back
#define		mkp			make_pair
#define		ll			long long
#define		pii			pair<int, int>
#define 	pll			pair<ll, ll>
#define 	vll			vector<ll>
#define 	vi			vector<int>
#define		no			cout<<"NO\n"
#define		yes			cout<<"YES\n"
#define		gcd(a, b)		__gcd(a, b)
#define		total_bit(a)		__builtin_popcount(a)
#define		lcm(a, b)		((a)*((b)/gcd(a,b)))
#define		REP(i,n)		for(int i = 0; i<n; i++)
#define		all(p)			p.begin(),p.end()
#define		mem(ar,val)		memset(ar, val, sizeof(ar))
#define 	UNIQUE(a)		sort(all(a)); a.erase(unique(all(a)), a.end())
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
    ll n, m;
    cin>>n>>m;
    m--;
    ll x, br[n];
    vector<ll> ar;
    ll val;
    for(ll i = 0; i<n; i++)
    {
        cin>>x;
        if(i != m)
            ar.push_back(x);
        else val = x;
    }
    deque<ll> dq;
    for(ll i = 0; i<n; i++)
    {
        cin>>br[i];
        if(i != 0)
            dq.push_back(br[i]);
    }
    val += br[0];
    ll ans = 1;
    for(ll i = 0; i<sz(ar); i++)
    {
        ll a = ar[i] + dq.front();
        ll b = ar[i] + dq.back();
//        cout<<a<<" "<<b<<nl;
        if(val < b)
        {
            ans++;
            dq.pop_front();
        }
        else
            dq.pop_back();

    }
    cout<<ans<<nl;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(NULL);
//	ll t;
//	cin>>t;
//	while(t--)
		solve();
	return 0;
}
