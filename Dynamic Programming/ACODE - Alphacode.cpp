//Problem Link: https://www.spoj.com/problems/ACODE/
#include<bits/stdc++.h>
#define	mod	1000000007
#define	ll	long long
#define	pb	push_back
#define	sz(v)	(int)v.size()
#define	nl	"\n"
#define		mem(ar,val)		memset(ar, val, sizeof(ar))
#define	REP(i,n)	for(int i = 1; i<=n; i++)
using namespace std;
const ll INF = 0x7f7f7f7f;

void solve()
{
	string s;
	while(cin>>s)
	{
		if(s == "0")
			return;

		int n = sz(s);
		ll dp[n];
		dp[0] = 1;
		int i;
		for(i = 1; i<n; i++)
		{
			int val = (s[i-1] -'0')  * 10 + (s[i] -'0');
			if(s[i] == '0')
			{
				if(i == 1)
					dp[i] = 1;
				else
					dp[i] = dp[i-2];
			}
			else
			{
				if(i == 1 && val>9 && val <= 26) 
					dp[i] = 2;
				else  if(val>9 && val <= 26)
					dp[i] = (dp[i-1] + dp[i-2]);
				else dp[i] = dp[i-1];

			}
//			cout<<dp[i]<<nl;			
		}
		cout<<dp[i-1]<<nl;
	}
}
int main()
{	
	solve();
	return 0;
}

