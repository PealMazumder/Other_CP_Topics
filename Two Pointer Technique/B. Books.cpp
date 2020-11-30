//Problem Link: https://codeforces.com/problemset/problem/279/B
#include<bits/stdc++.h>
#define	ll	long long
#define	pb	push_back
#define	sz(v)	(int)v.size()
#define	nl	"\n"
using namespace std;

void solve()
{
	ll n, t;
	cin>>n>>t;
	ll ar[n];
	
	for(ll i = 0; i<n; i++)
	{
		cin>>ar[i];
	}
	ll l = 0, r = 0;
	ll tsum = 0, ans = 0;
	while(r<n)
	{
		tsum += ar[r];
		if(tsum >= t)
		{
			ans = max(ans, r - l);
			while(tsum > t && l <= r)
			{
				tsum -= ar[l];
				l++;
			}
		}
		r++;
	}
	ans = max(ans, r - l);
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

