///Problem Link: https://atcoder.jp/contests/dp/tasks/dp_d
#include<bits/stdc++.h>
#define	ll	long long
#define	pb	push_back
#define	sz(v)	(int)v.size()
#define	nl	"\n"
using namespace std;

void solve()
{
	int n, w, weight, value;
	cin>>n>>w;
	vector<ll> dp(w+1);
	for(int i = 0; i<n; i++)
	{
		cin>>weight>>value;
		for(int j = w - weight; j >= 0; j--)
		{
			dp[weight+j] = max(dp[weight+j], dp[j] + value);
		}
	}
	ll ans = 0;
	for(int i = 0; i<=w; i++)
		ans = max(ans, dp[i]);
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
