///Problem Link: http://codeforces.com/contest/1430/problem/E
#include<bits/stdc++.h>
#define	ll	long long
#define	pb	push_back
#define	sz(v)	(int)v.size()
#define	nl	"\n"
using namespace std;
const int mx = 200005;
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
void update(int idx, int val, int n)
{
	while(idx <= n)
	{
		tree[idx] += val;
		idx += idx & -idx;
	}
}
void solve()
{
	int n; 
	string s;
	cin>>n>>s;
	queue<int> a[27];
	for(int i = 0; i<n; i++)
		a[s[i] - 'a'].push(i+1);
	vector<int> ar;
	ar.pb(0);
	for(int i = n-1; i>=0; i--)
	{
		ar.pb(a[s[i] - 'a'].front());
		a[s[i] - 'a'].pop();
	}
	ll cnt = 0;
	for(int i = 1; i<=n; i++)
	{
		update(ar[i], 1, n);
		cnt += (read(n) - read(ar[i]));
		 
	}
	cout<<cnt<<nl;
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


