//Problem Link: https://codeforces.com/contest/1430/problem/B
#include<bits/stdc++.h>
#define	ll	long long
#define	pb	push_back
#define	sz(v)	(int)v.size()
#define	nl	"\n"
using namespace std;
ll comp(ll a, ll b)
{
	return a>b;
}
void solve()
{
	ll n, k;
	cin>>n>>k;
	ll ar[n];
	for(ll i = 0; i<n; i++)	
		cin>>ar[i];
	sort(ar, ar+n, comp);
	
	ll ans = 0;
	for(ll i = 0; i<=k; i++)
		ans += ar[i];
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


