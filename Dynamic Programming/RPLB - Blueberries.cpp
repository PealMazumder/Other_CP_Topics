//Problem Link: https://www.spoj.com/problems/RPLB/
#include<bits/stdc++.h>
#define	mod	1000000007
#define	ll	long long
#define	pb	push_back
#define	sz(v)	(int)v.size()
#define	nl	"\n"
#define		mem(ar,val)		memset(ar, val, sizeof(ar))
using namespace std;
int casino = 0;
int dp[1001][1001];
int maxiBlueberries(int idx, int weight, vector<int> &ar, int k)
{
	if(idx >= sz(ar))
		return weight;
	if(dp[idx][weight] != -1)
		return dp[idx][weight];
	if(weight + ar[idx] <= k)
	{
		int a = maxiBlueberries(idx+2, weight+ar[idx], ar, k);
		int b = maxiBlueberries(idx+1, weight, ar, k);
		dp[idx][weight] = max(a, b);
	}
	else
		dp[idx][weight] = maxiBlueberries(idx+1, weight, ar, k);
	
	return dp[idx][weight];
}
void solve()
{
	mem(dp, -1);
	int n, k;
	scanf("%d %d",&n, &k);
	vector<int> ar(n);
	for(int i = 0; i<n; i++)
		scanf("%d",&ar[i]);
	int ans = maxiBlueberries(0, 0, ar, k);
	printf("Scenario #%d: %d\n",++casino, ans);
	
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	    solve();

	return 0;
}

