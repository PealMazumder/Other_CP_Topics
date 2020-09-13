//Problem Link: https://www.spoj.com/problems/AIBOHP/
#include<bits/stdc++.h>
#define	ll	long long
#define	pb	push_back
#define	sz(v)	(int)v.size()
#define	nl	"\n"
using namespace std;
int dp[6101][6101];
int minimumChar(string &s, int x, int y)
{
	if(x >= y )
		return 0;
	if(dp[x][y] != -1) 
		return dp[x][y];
	if(s[x] != s[y])
	{
		int a = minimumChar(s, x+1, y) + 1;
		int b = minimumChar(s, x, y-1) + 1;
		dp[x][y] = min(a,b);
	}
	else
		dp[x][y] = minimumChar(s, x+1, y-1);
	return dp[x][y];
}
void solve()
{
	memset(dp, -1, sizeof(dp));
	string s;
	cin>>s;
	int ans = minimumChar(s, 0, sz(s)-1);
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

