//Problem Link: https://www.codechef.com/problems/CHEFSETC
#include<bits/stdc++.h>
#define	mod	1000000007
#define	ll	long long
#define	pb	push_back
#define	nl	"\n"
#define	REP(i,n)	for(int i = 1; i<=n; i++)
using namespace std;
int n, m, i, j, k, a, b, c, sum;
void solve()
{
	int ar[4];
	for(i = 0; i<4; i++)
		cin>>ar[i];
	for(i = 1; i < (1 << 4); i++)
	{
		sum = 0;
		for(j = 0; j<4; j++)
		{
			if((i & (1 << j)) != 0)
				sum += ar[j];
		}
		if(sum == 0)
		{
			cout<<"Yes\n";
			return;
		}
	}
	cout<<"No\n";
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

