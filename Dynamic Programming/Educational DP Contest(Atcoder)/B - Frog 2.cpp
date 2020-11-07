///Problem Link: https://atcoder.jp/contests/dp/tasks/dp_b
#include<bits/stdc++.h>
#define	ll	long long
#define	pb	push_back
#define	sz(v)	(int)v.size()
#define	nl	"\n"
using namespace std;
const int mx = 100005;
int n, k, h[mx], dp[mx];
ll minimumCost(int i)
{
	if(i == n-1)
		return abs(h[i] - h[i+1]);
		
	if(i >= n) return 0;
	
	if(dp[i] != -1)
		return dp[i];
	
	ll a, b = INT_MAX;
	for(int j = 1; (j <= k ) && (i + j <= n); j++)
	{
		a = minimumCost(i+j) + abs(h[i] - h[i+j]);
		b = min(a, b);
	}
	
	return dp[i] = b;
}
void solve()
{
	cin>>n>>k;
	
	
	for(int i = 1; i<=n; i++)
	{
		cin>>h[i];
		dp[i] = -1;
	}
	
	ll ans = minimumCost(1);
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

