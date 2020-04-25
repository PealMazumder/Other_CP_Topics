/*
  Problem Link: https://www.codechef.com/problems/SUMTRIAN
*/

#include<bits/stdc++.h>
#define		fast			ios::sync_with_stdio(false);cin.tie(0);cout.tie(NULL);
#define		rep(i,n)		for(int i = 1; i<=n; i++)
#define		all(p)			p.begin(),p.end()
#define		mem(ar,val)		memset(ar, val, sizeof(ar))
#define		sz(c)			(int)c.size()
#define		pb(x)			push_back(x)
#define		mkp(x,y)		make_pair(x,y)
#define 	deb			cout<<"hehehe\n"
#define		ff			first
#define		ss			second
#define 	pf 			printf
#define 	sf 			scanf
#define		ll			long long
#define		pii			pair<int, int>
#define 	pll			pair<ll, ll>
#define 	vll			vector<long long>
#define 	vi			vector<int>
#define		nl			"\n"
#define		pnl			cout<<"\n"
#define 	total_bit(a)		__builtin_popcount(a)
#define 	UNIQUE(a)		sort(all(a)); a.erase(unique(all(a)), a.end())
#define		FI			freopen("input.txt", "r", stdin);
#define 	FO			freopen("output.txt", "w", stdout);
using namespace std;
const int INF = 0x7f7f7f7f;
const int M = 1e9 + 7;
const int N = 1e6+7;
int main()
{
	fast
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int ar[n][n];
		for(int i = 0; i<n; i++)
			for(int j = 0; j <= i; j++)
				cin>>ar[i][j];
		for(int i = n - 2; i>=0; i--)
		{
			for(int j = 0; j <= i; j++)
			{
				int tm1 = ar[i][j] + ar[i+1][j];
				int tm2 = ar[i][j] + ar[i+1][j+1];
				ar[i][j] = max(tm1, tm2);
			}
		}
		cout<<ar[0][0]<<nl;			
	}
    return 0;
}

