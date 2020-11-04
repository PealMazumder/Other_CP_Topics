///Problem Link: https://codeforces.com/contest/1445/problem/C
#include<bits/stdc++.h>
#define	ll	long long
#define	pb	push_back
#define	sz(v)	(int)v.size()
#define	nl	"\n"
#define		all(p)			p.begin(),p.end()
#define 	UNIQUE(a)		sort(all(a)); a.erase(unique(all(a)), a.end())
using namespace std;
vector<ll> Divisor(ll q)
{
	vector<ll> d;
	d.pb(q);
	for(ll i = 2; i*i<=q; i++)
	{
		if(q%i==0)
		{
			d.pb(i);
			if(i != q/i)
				d.pb(q/i);
		}
	}
	return d;
}
void solve()
{
	ll p, q, cpyP;
	cin>>p>>q;
	vector<ll> divisors = Divisor(q);
	if(p%q != 0)
	{
		cout<<p<<nl;
		return;
	}
	ll ans = 1;
	for(auto x : divisors)
	{
		cpyP = p;
		while(cpyP % x == 0)
		{
			cpyP = cpyP/ x;
			if(cpyP%q != 0)
			{
				ans = max(ans, cpyP);
				break;
			}
		}
	}
	cout<<ans<<nl;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(NULL);
 
	int t;
	cin>>t;
	while(t--)
	    solve();
 
	return 0;
}
