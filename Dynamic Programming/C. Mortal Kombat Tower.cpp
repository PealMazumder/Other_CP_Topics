//Problem Link: http://codeforces.com/contest/1418/problem/C
#include<bits/stdc++.h>
#define	ll	long long
#define	pb	push_back
#define	sz(v)	(int)v.size()
#define	nl	"\n"
using namespace std;
int dp[200001][2];
int minSkipPoint(vector<int> &ar, int i, int flag)
{
	if(i >= sz(ar)) return 0;
	if(dp[i][flag] != -1) return dp[i][flag];
	int a, b; a = b = 100000000;
	if(flag)
	{
		a = ar[i] + minSkipPoint(ar, i+1, flag^1);
		if(i+1 < sz(ar))
			b = ar[i] + ar[i+1] + minSkipPoint(ar, i+2, flag^1);
	}
	else
	{
		a = minSkipPoint(ar, i+1, flag^1);
		b =  minSkipPoint(ar, i+2, flag^1);
	}
	
	return dp[i][flag] = min(a, b);	
}
void solve()
{
	int n;
	cin>>n;
	vector<int> ar(n);
	for(int i = 0; i<n; i++)
		cin>>ar[i];
	memset(dp, -1, sizeof(dp));
	int ans = minSkipPoint(ar, 0, 1);
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

