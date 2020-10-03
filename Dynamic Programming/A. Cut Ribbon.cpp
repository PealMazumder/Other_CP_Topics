//Problem Link: http://codeforces.com/contest/189/problem/A
#include<bits/stdc++.h>
#define	ll	long long
#define	pb	push_back
#define	sz(v)	(int)v.size()
#define	nl	"\n"
using namespace std;
int dp[4002];
int  mn = INT_MAX;
vector<int> ar(4);
int  maximumRibbon(int nn)
{
	if(nn < mn && nn != 0) return INT_MIN;
	if(dp[nn] != -1) return dp[nn];
	int a, b, c;
	a = b = c = INT_MIN;
	if(nn >= ar[0])
		a = maximumRibbon(nn-ar[0]) + 1;
		
	if(nn >= ar[1])
		b = maximumRibbon(nn-ar[1]) + 1;

	if(nn >= ar[2])
		c = maximumRibbon(nn-ar[2]) + 1;
		
	return dp[nn] = max(max(a, b), c);
}
void solve()
{
	int n;
	cin>>n;
	memset(dp, -1, sizeof(dp));
	for(int i = 0; i<3; i++)
	{
		cin>>ar[i];
		if(ar[i]<mn) mn = ar[i];
	}
	dp[0] = 0;
	int ans = maximumRibbon(n);
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


