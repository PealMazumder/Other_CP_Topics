///Problem Link: https://www.spoj.com/problems/KNAPSACK/
#include<bits/stdc++.h>
#define	ll	long long
#define	pb	push_back
#define	sz(v)	(int)v.size()
#define	nl	"\n"
using namespace std;

void solve()
{
	int s, n, size, value;
	cin>>s>>n;
	vector<int> dp(s+1);
	for(int i = 0; i<n; i++)
	{
		cin>>size>>value;
		for(int j = s - size; j >= 0; j--)
		{
			dp[size+j] = max(dp[size+j], dp[j] + value);
		}
	}
	int ans = 0;
	for(int i = 0; i<=s; i++)
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


