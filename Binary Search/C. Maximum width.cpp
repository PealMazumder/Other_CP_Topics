//Problem Link: https://codeforces.com/contest/1492/problem/C
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
	ll n, m, i, j;
	string s, t;
	cin>>n>>m>>s>>t;
	vector<vll> v(27);
	for(i = 0; i < n; i++){
		v[s[i]-'a'].pb(i);
	}
	vector<ll> mx, mn;
	mn.pb(v[t[0]-'a'][0]);
	for(i = 1; i<m; i++)
    {
        auto xx = upper_bound(v[t[i]-'a'].begin(), v[t[i]-'a'].end(), mn[i-1]);
        mn.pb(*xx);
    }
    mx.pb(v[t[m-1]-'a'].back());
	for(i = m-2, j = 0; i>=0; i--, j++)
    {
        auto xx = lower_bound(v[t[i]-'a'].begin(), v[t[i]-'a'].end(), mx[j]);
        xx--;
        mx.pb(*xx);
    }
    reverse(mx.begin(), mx.end());
    ll ans = 1;
    for(i = 0; i<m-1; i++)
    {
        ans = max(ans, mx[i+1]- mn[i]);
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
