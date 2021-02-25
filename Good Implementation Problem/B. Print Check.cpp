//Problem Link: https://codeforces.com/contest/631/problem/B
#include<bits/stdc++.h>
#define		nl			"\n"
#define		mod			1000000007
#define		sz(c)			(int)c.size()
#define		pb			push_back
#define		mkp			make_pair
#define 	deb			cout<<"ok\n"
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
	ll n, m, k;
	cin>>n>>m>>k;
	map<ll, pair<ll,ll> > r, cc;
	for(ll i = 0; i<k; i++)
    {
        ll a, b, c;
        cin>>a>>b>>c;
        if(a == 1)
            r[b] = {i, c};
        else
            cc[b] = {i, c};
    }
    map<ll, pair<ll, ll> > row, col;
    for(auto xx : r)
    {
        ll tm = xx.second.first;
        row[tm] = {xx.first, xx.second.second};
    }
    for(auto xx : cc)
    {
        ll tm = xx.second.first;
        col[tm] = {xx.first, xx.second.second};
    }
    auto it = row.begin();
    auto it1 = col.begin();
    ll ans[n+1][m+1]= {0};
    while(true)
    {
        if(it == row.end() && it1 == col.end())
            break;

        ll x, y;

        if(it == row.end())
            x = INT_MAX;
        else
            x = it->first;

        if(it1 == col.end())
            y = INT_MAX;
        else
            y = it1->first;

        if(x < y)
        {
            ll tm = it->second.first;
            ll val = it->second.second;
            for(ll i = 1;i<=m; i++)
                ans[tm][i] = val;
            it++;
        }
        else
        {
            ll tm = it1->second.first;
            ll val = it1->second.second;
            for(ll i = 1;i<=n; i++)
                ans[i][tm] = val;
            it1++;
        }
    }
    for(ll i = 1; i<=n; i++)
    {
        for(ll j = 1; j<=m;j++)
            cout<<ans[i][j]<<" ";
        cout<<nl;
    }

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
