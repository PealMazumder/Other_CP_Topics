/*
  Problem Link: https://www.codechef.com/ZCOPRAC/problems/ZCO14002
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
	int n;
	cin>>n;
	int ar[n+1];
	for(int i = 1; i<=n; i++)
		cin>>ar[i];
	for(int i = n-3; i>0; i--)
	{
		ar[i] += min(ar[i+1], min(ar[i+2],ar[i+3]));
	}
	int ans = min(ar[1], min(ar[2],ar[3]));
	cout<<ans<<nl;
    return 0;
}

