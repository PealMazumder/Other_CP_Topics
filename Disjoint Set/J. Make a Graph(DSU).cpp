///Problem Link: https://www.codeto.win/contest/38/problem/J
#include<bits/stdc++.h>
#define	ll	long long
#define	pb	push_back
#define	sz(v)	(ll)v.size()
#define	nl	"\n"
using namespace std;
const ll N = 1000005;
ll par[N], Size[N];
ll casino = 0;
void make_set(ll v)
{
	par[v] = v;
	Size[v] = 1;
}
ll find_set(ll v)
{
	if(v == par[v])
		return v;
	return par[v] = find_set(par[v]);
}
void union_sets(ll a, ll b)
{
	a = find_set(a);
	b = find_set(b);
	if(a != b)
	{
		if(Size[a] < Size[b])
			swap(a, b);
		par[b] = a;
		Size[a] += Size[b];
		Size[b] = -1;
	}
}
void solve()
{
	ll n;
	cin>>n;
	ll ar[n];
	ll ans = 0, oneC = 0;
	vector<ll> v;
	memset(Size, 0, sizeof(Size));
	memset(par, 0, sizeof(par));
	for(ll i = 0; i<n; i++)
	{
		cin>>ar[i];
		if(ar[i] == 1) oneC++;
		ll curr = ar[i], pre = -1;
		bool ck = false;
		for(ll j = 2; j*j <= curr; j++)
		{
			if(!(curr % j))
			{
				while(!(curr % j))
					curr /= j;	
				if(Size[j] == 0)
					make_set(j);
				if(pre != -1)
					union_sets(pre, j);
					
				pre = j;
			}
		}
		if(curr>1)
		{
			if(Size[curr] == 0)
				make_set(curr);
			if(pre != -1)
				union_sets(pre, curr);
			pre = curr;
		}
		v.pb(pre);
	}
	map<ll, bool> mp;
	for(ll i = 0; i<sz(v); i++)
	{
		ll a = find_set(v[i]);
		if(mp[a] == false)
			ans++;
		mp[a] = true;
	}
	if(oneC>1)
		ans+=(oneC-1);
	cout<<"Case "<<++casino<<": "<<ans<<nl;
	
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(NULL);

	ll t;
	cin>>t;
	while(t--)
	    solve();

	return 0;
}


