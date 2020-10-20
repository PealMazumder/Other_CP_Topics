///Problem Link: https://www.hackerrank.com/challenges/easy-gcd-1/problem
#include<bits/stdc++.h>
#define	ll	long long
#define	pb	push_back
#define	sz(v)	(int)v.size()
#define	nl	"\n"
using namespace std;
map<ll, ll> mp;
vector<ll> PrimeFact(ll n)
{
	vector<ll> ret;
	for(ll i = 2; i*i<=n; i++)
	{
		if(n%i == 0)
		{
			ret.pb(i);
			int cnt = 0;
			while(n && n%i == 0)
				cnt++,n /= i;
			mp[i] = cnt;
		}
	}
	if(n>1)
	{
		ret.pb(n);
		mp[n] = 1;
	}
	return ret;
}
void solve()
{
	ll n, k;
	cin>>n>>k;
	ll ar[n];
	ll mn = INT_MAX;
	for(ll i = 0; i<n; i++)
	{
		cin>>ar[i];
		mn = min(mn, ar[i]);
	}
	vector<ll> pf = PrimeFact(mn);
	for(ll i = 0; i<n; i++)
	{
		for(ll j = 0; j<sz(pf); j++)
		{
			ll cnt = 0;
			while(ar[i] % pf[j] == 0)
				cnt++, ar[i] /= pf[j];
				
			if(mp[pf[j]] != 0)
				mp[pf[j]] = min(mp[pf[j]], cnt);
		}
	}
	ll x = 0;
	for(auto xx : mp)
	{
		if(xx.second != 0)
		{
			x = xx.first;
			break;
		}
	}
	ll xxx = k/x;
	cout<<xxx * x<<nl;
}
int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(NULL);

//	int t;
//	cin>>t;
//	while(t--)
	    solve();

	return 0;
}


