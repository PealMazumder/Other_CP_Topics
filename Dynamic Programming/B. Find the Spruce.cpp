//Problem Link: https://codeforces.com/contest/1461/problem/B
#include<bits/stdc++.h>
#define	ll	long long
#define	pb	push_back
#define	sz(v)	(int)v.size()
#define	nl	"\n"
using namespace std;
int dp[501][501][2];
int n, m;
int numberOfSpruce(int i, int j)
{
	if(i < 1 || j < 1 || i > n || j > m)
		return 0;
	if(i == n) return dp[i][j][0];
	if(dp[i][j][0] == 0 || dp[i][j][1] != 0) return dp[i][j][1];
	
	int a, b, c;
	a = numberOfSpruce(i+1, j) + 1;
	b = numberOfSpruce(i+1, j-1) + 1;
	c = numberOfSpruce(i+1, j + 1) + 1;
	
	return dp[i][j][1] = min(a, min(b, c));
}
void solve()
{
	cin>>n>>m;
	char ar[n+1][m+1];
	memset(dp, 0, sizeof(dp));
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			cin>>ar[i][j];
			if(ar[i][j] == '*')
				dp[i][j][0] = 1;
		}
	}
	ll ans = 0;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(ar[i][j] == '*')
				ans += numberOfSpruce(i, j);
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


