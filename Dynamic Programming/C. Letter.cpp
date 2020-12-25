//Problem Link: https://codeforces.com/problemset/problem/180/C
#include<bits/stdc++.h>
#define	ll	long long
#define	pb	push_back
#define	sz(v)	(int)v.size()
#define	nl	"\n"
using namespace std;
int dp[100005][2];
string s;
void solve()
{
	cin>>s;
	memset(dp, 0, sizeof(dp));
	for(int i = 1; i<=sz(s); i++)
	{
		if(s[i-1] <= 90)
			dp[i][0] = dp[i-1][0];
		else dp[i][0] = dp[i-1][0]+1;
		
		if(s[i-1] >= 97)
			dp[i][1] = dp[i-1][1];
		else
			dp[i][1] = min(dp[i-1][1] + 1, dp[i][0]);	
	}
	cout<<dp[sz(s)][1]<<nl;
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


