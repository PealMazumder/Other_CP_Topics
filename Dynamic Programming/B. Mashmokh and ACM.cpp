///https://codeforces.com/problemset/problem/414/B
#include<bits/stdc++.h>
#define	ll	long long
#define	pb	push_back
#define	sz(v)	(int)v.size()
#define	nl	"\n"
#define mod 1000000007
using namespace std;
int dp[2005][2005];
int numberOfGoodSequence(int n, int k, int val)
{
	if(k <= 0) return 1;
	if(dp[k][val] != -1) return dp[k][val];
	
	int ans = 0;
	for(int next = val; next <= n; next += val)
	{
		if(next % val == 0)
			ans = (ans + numberOfGoodSequence(n, k-1, next)) % mod;
	}
	return dp[k][val] = ans;
}
void solve()
{
	int n, k;
	cin>>n>>k;
	memset(dp, -1, sizeof(dp));
	int ans = numberOfGoodSequence(n, k, 1);
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

