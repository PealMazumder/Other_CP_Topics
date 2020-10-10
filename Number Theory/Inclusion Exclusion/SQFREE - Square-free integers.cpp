///Problem Link: https://www.spoj.com/problems/SQFREE/
#include<bits/stdc++.h>
#define	ll	long long
#define	pb	push_back
#define	sz(v)	(int)v.size()
#define	nl	"\n"
using namespace std;
const int mx = 1e7 + 1;
vector<int> prime;
bool vis[mx];
int mu[mx];
void sieve()
{
	for(int i = 3; i*i<mx; i += 2)
	{
		if(vis[i] == false)
			for(int j = i*i; j<mx; j += 2*i)
				vis[j] = true;
	}
	prime.pb(2);
	for(int i = 3; i<mx; i+=2)
		if(!vis[i])
			prime.pb(i);
}
void mobius()
{
	for(int i = 1; i<mx; i++) mu[i] = 1;
	for(int i = 0; i<prime.size() && prime[i]*prime[i]<mx; i++)
	{
		int x = prime[i];
		x *= x;
		for(int j = x; j<mx; j+=x)
			mu[j] = 0;
	}
	for(int i = 0; i<prime.size(); i++)
	{
		int x = prime[i];
		for(int j = x; j<mx; j+=x)
			mu[j] *= -1;
	}
}
void solve()
{
	ll n;
	cin>>n;
	ll ans = 0;
	for(ll i = 1; i*i<=n; i++)
	{
		ans += (mu[i] * (n/(i*i)));
	}
	cout<<ans<<nl;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(NULL);
	sieve();
	mobius();
	int t;
	cin>>t;
	while(t--)
	    solve();

	return 0;
}


