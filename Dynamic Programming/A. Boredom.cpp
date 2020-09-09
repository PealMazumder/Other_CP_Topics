//Problem Link: https://codeforces.com/contest/455/problem/A
#include<bits/stdc++.h>
#define	mod	1000000007
#define	ll	long long
#define	pb	push_back
#define	sz(v)	(int)v.size()
#define	nl	"\n"
#define		mem(ar,val)		memset(ar, val, sizeof(ar))
using namespace std;
const int N = 100001;
void solve()
{
	int n, a;
	cin>>n;
	map<int, int> mp;
	for(int i = 0; i<n; i++)
	{
		cin>>a;
		mp[a]++;
	}
	ll mx1 = mp[1], mx2 = 0, curr;
	for(ll i = 2; i<100001; i++)
	{
		curr = max(mx1, i*mp[i] + mx2);
		mx2 = mx1;
		mx1 = curr;
	}
	cout<<mx1<<nl;
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

