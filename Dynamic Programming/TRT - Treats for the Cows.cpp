//Problem Link: https://www.spoj.com/problems/TRT/
#include<bits/stdc++.h>
#define	ll	long long
#define	pb	push_back
#define	sz(v)	(int)v.size()
#define	nl	"\n"
using namespace std;
int dp[2002][2002];
int maximumRevenue(vector<int> &ar, int st, int en, int age)
{
	if(st > en) return 0;
	if(dp[st][en] != -1) return dp[st][en];
	
	int a = ar[st] * age + maximumRevenue(ar, st+1, en, age+1);
	int b = ar[en] * age + maximumRevenue(ar, st, en-1, age+1);
	
	return dp[st][en] = max(a, b);
}
void solve()
{
	int n;
	cin>>n;
	vector<int> ar(n);
	for(int i = 0; i<n; i++)
		cin>>ar[i];
	memset(dp, -1, sizeof(dp));
	
	int ans = maximumRevenue(ar, 0, n-1, 1);
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


