/*
  Problem Link: https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/bike-trip/description/
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
		ll ftrt[n],strt[n],fctrt[n],sctrt[n];
		for(int i = 0; i<n; i++)
			cin>>ftrt[i];
		for(int i = 0; i<n; i++)
			cin>> strt[i];
		for(int i = 0; i<n-1; i++)
			cin>>fctrt[i];
		for(int i = 0; i<n-1; i++)
			cin>>sctrt[i];
			
		for(int i = n-2; i>=0; i--)
		{
			ll tm1, tm2;
			tm1 = ftrt[i] + ftrt[i+1];
			tm2 = ftrt[i] + fctrt[i] + strt[i+1];
			ftrt[i] = min(tm1, tm2);
			tm1 = strt[i] + strt[i+1];
			tm2 = strt[i] + sctrt[i] + ftrt[i+1];
			strt[i] = min(tm1, tm2);
		}
		ll ans = min(ftrt[0],strt[0]);
		cout<<ans<<nl;
	}
    return 0;
}


