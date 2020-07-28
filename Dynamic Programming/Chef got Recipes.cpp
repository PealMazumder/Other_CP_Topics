// Problem Link: https://www.codechef.com/problems/JAIN
#include<bits/stdc++.h>
#define	sz(v)	(int)v.size()
#define	mod	1000000007
#define	ll	long long
#define	pb	push_back
#define	nl	"\n"
#define	REP(i,n)	for(int i = 1; i<=n; i++)
using namespace std;
int n, m, i, j, k, a, b, c;
void solve()
{
	int fre[32] = {0};
	cin>>n;
	string s;
	for(i = 0; i<n; i++)
	{
		cin>>s;
		int mask = 0;
		for(char x : s)
		{
			if(x == 'a') mask |= (1 << 0);
			else if(x == 'e') mask |= (1 << 1);
			else if(x == 'i') mask |= (1 << 2);
			else if(x == 'o') mask |= (1 << 3);
			else mask |= (1 << 4);
		}
		fre[mask]++;
	}
	ll ans = 0;
	for(i = 1; i < 32; i++)
	{
		for(j = i+1; j < 32; j++)
		{
			if((i | j) == 31)
				ans += fre[i] * fre[j];
		}
	}
	ans += (fre[31] * (fre[31] -1 )) / 2;
	cout<<ans<<nl;
}
int main()
{
//	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(NULL);
	
	int t;
	cin>>t;
	while(t--)
	    solve();

	return 0;
}

