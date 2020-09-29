//Problem Link: https://codeforces.com/contest/698/problem/A
#include<bits/stdc++.h>
#define	ll	long long
#define	pb	push_back
#define	sz(v)	(int)v.size()
#define	nl	"\n"
using namespace std;
int dp[102][3];
int minimumRest(vector<int> &ar, int n, int i, int pre)
{
	if(i >= n) return 0;
	if(dp[i][pre] != -1) return dp[i][pre];
	
	if(ar[i] == 0)
		dp[i][pre] = minimumRest(ar, n, i+1, 0) + 1;
	else if(ar[i] == 1)
	{
		if(pre == 1)
			dp[i][pre] = minimumRest(ar, n, i+1, 0) + 1;
		else
			dp[i][pre] = minimumRest(ar, n, i+1, 1);
	}
	else if(ar[i] == 2)
	{
		if(pre == 2)
			dp[i][pre] = minimumRest(ar, n, i+1, 0) + 1;
		else
			dp[i][pre] = minimumRest(ar, n, i+1, 2);
	}
	else
	{
		int a = INT_MAX, b = INT_MAX;
		if(pre == 1|| pre == 0)
			a = minimumRest(ar, n, i+1, 2);
		
		if(pre == 2|| pre == 0)
			b = minimumRest(ar, n, i+1, 1);	
			
		dp[i][pre] = min(a, b);
	}
	return dp[i][pre];
}
void solve()
{
	int n;
	cin>>n;
	vector<int> ar(n);
	for(int i = 0; i<n; i++)
		cin>>ar[i];
	memset(dp, -1, sizeof(dp));
	int ans = minimumRest(ar, n, 0, 0);
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


