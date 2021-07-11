///Problem Link: https://www.codechef.com/problems/DYNAINV
#include<bits/stdc++.h>
#define	ll	long long
#define	pb	push_back
#define	sz(v)	(int)v.size()
#define	nl	"\n"
using namespace std;
const int mx = 100005;
int tree[mx];
int read(int idx)
{
	int sum = 0;
	while(idx > 0)
	{
		sum += tree[idx];
		idx -= idx & -idx;
	}
	return sum;
}
void update(int idx, int val)
{
	while(idx < mx)
	{
		tree[idx] += val;
		idx += idx & -idx;
	}
}
void solve()
{
	int n, q, x, i, j;
	cin>>n>>q;
	int ans = 0;
	for(i = 0; i<n; i++)
	{
		cin>>x;
		ans =(ans + read(mx) - read(x)) % 2;
		update(x, 1);
	}
	while(q--)
	{
		cin>>i>>j;
		ans ^= 1;
		cout<<ans<<nl;	
	}
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
