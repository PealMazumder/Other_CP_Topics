///Problem Link: http://codeforces.com/problemset/problem/545/C
#include<bits/stdc++.h>
#define	ll	long long
#define	pb	push_back
#define	sz(v)	(int)v.size()
#define	nl	"\n"
using namespace std;

void solve()
{
	ll n, x, h;
	cin>>n;
	vector<pair<ll, ll> > ar;
	for(ll i = 0; i<n; i++)
	{
		cin>>x>>h;
		ar.pb({x, h});
	}
	ll ans = 1, pre = ar[0].first;
	for(ll i = 1; i<n; i++)
	{
		if(pre >= ar[i].first)
		{
			ans --;
			pre =  ar[i-1].first;
		}
		if(ar[i].first - ar[i].second > pre)
		{
			pre = ar[i].first;
			ans++;
//			cout<<ar[i].first<<" "<<ar[i].second<<nl;
		}
		else if(ar[i].first > pre)
		{
			pre = ar[i].first + ar[i].second;
			ans++;
//			cout<<ar[i].first<<" "<<ar[i].second<<nl;
		}
	
	}
	cout<<ans<<nl;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(NULL);

	//	int t;
	//	cin>>t;
	//	while(t--)
	    solve();

	return 0;
}


