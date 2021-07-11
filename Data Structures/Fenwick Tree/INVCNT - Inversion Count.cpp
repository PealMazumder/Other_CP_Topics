///Problem Link: https://www.spoj.com/problems/INVCNT/
#include<bits/stdc++.h>
#define	ll	long long
#define	pb	push_back
#define	sz(v)	(int)v.size()
#define	nl	"\n"
using namespace std;
const int mx  = 200005;
int tree[mx];
int read(int idx)
{
	int sum = 0;
	while(idx > 0)
	{
		sum += tree[idx];
		idx -= (idx & -idx);
	}
	return sum;
}
void update(int idx,int val)
{
	while(idx < mx)
	{
		tree[idx] += val;
		idx += (idx & -idx);
	}	
}
void solve()
{
	memset(tree, 0, sizeof(tree));
	int n;
	cin>>n;
	int ar[n+1];
	map<int, int> mp;
	for(int i = 1; i<=n; i++)
	{
		cin>>ar[i];
		mp[ar[i]]=0;
	}
	int cnt = 1;
	for(auto xx : mp)
	{
		mp[xx.first] = cnt;
		cnt++;	
	}		
	for(int i = 1; i <= n; i++)
		ar[i] = mp[ar[i]];
	ll ans = 0;
	for(int i = 1; i<=n; i++)
	{
		update(ar[i], 1);
		ans += (read(mx-1) - read(ar[i]));
	}
	cout<<ans<<nl;
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


