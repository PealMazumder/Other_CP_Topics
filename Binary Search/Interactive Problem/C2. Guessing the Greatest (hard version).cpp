//Problem Link: https://codeforces.com/contest/1486/problem/C2
#include<bits/stdc++.h>
#define	ll	long long
#define	pb	push_back
#define	sz(v)	(int)v.size()
#define	nl	"\n"
using namespace std;
int query(int l, int r)
{
	cout<<"? "<<l<<" "<<r<<endl;
	int x;
	cin>>x;
	return x;
}
void solve()
{
	int n;
	cin>>n;
	int pos = query(1, n);
	
	if(1 < pos && query(1, pos) == pos)
	{
		int l = 1, r = pos;
		while(l<r-1)
		{
			int m = (l+r)/2;
			if(query(m, pos) == pos)
				l = m;
			else r = m;
		}
		cout<<"! "<<l<<endl;
	}
	else
	{
		int l = pos, r = n;
		while(l < r-1)
		{
			int m = (l+r)/2;
			if(query(pos, m) == pos)
				r = m;
			else l = m;
		}
		cout<<"! "<<r<<endl;
	}
}
int main()
{
//	ios::sync_with_stdio(false);
//	cin.tie(0);cout.tie(NULL);

//	int t;
//	cin>>t;
//	while(t--)
	    solve();

	return 0;
}


