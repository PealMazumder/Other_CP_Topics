///Problem Link: https://atcoder.jp/contests/dp/tasks/dp_c
#include<bits/stdc++.h>
#define	ll	long long
#define	pb	push_back
#define	sz(v)	(int)v.size()
#define	nl	"\n"
using namespace std;
const int mx = 100005;
int n, activities[mx][4], dp[mx][4];
ll maximumPoint(int day, int activity)
{
	if(day > n) return 0;
	
	if(dp[day][activity] != -1)
		return dp[day][activity];
	
	ll a, b;
	if(activity == 1)
	{
		a = maximumPoint(day + 1, 2) + activities[day][activity];
		b = maximumPoint(day + 1, 3) + activities[day][activity];
	}
	else if( activity == 2)
	{
		a = maximumPoint(day + 1, 1) + activities[day][activity];
		b = maximumPoint(day + 1, 3) + activities[day][activity];
	}
	else
	{
		a = maximumPoint(day + 1, 1) + activities[day][activity];
		b = maximumPoint(day + 1, 2) + activities[day][activity];
	}
	return dp[day][activity] = max(a, b);
}
void solve()
{
	cin>>n;
	
	for(int i = 1; i<=n; i++)
	{
		for(int j = 1; j <= 3; j++)
		{
			cin>>activities[i][j];
			dp[i][j] = -1;
		}
	}
	ll ans = 0;
	
	for(int i = 1; i<=3; i++)
		ans = max(ans, maximumPoint(1, i));
		
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
