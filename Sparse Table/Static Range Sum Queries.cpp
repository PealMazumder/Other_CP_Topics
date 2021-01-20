//Problem Link: https://cses.fi/problemset/task/1646/
#include<bits/stdc++.h>
#define	ll	long long
#define	pb	push_back
#define	sz(v)	(int)v.size()
#define	nl	"\n"
using namespace std;
const int mxn = 1000000;
struct RSQ
{
	static const int K = 24;
	ll st[mxn][K];
	
	void calc(int N, ll *array)
	{
		for(int i = 0; i<N; i++)
			st[i][0] = array[i];
		for(int j = 1; j <= K; j++)
			for(int i = 0; i + (1 << j) <= N; i++)
				st[i][j] = st[i][j-1] + st[i + (1 << (j-1))][j-1];
	}
	ll query(int L, int R) 
	{
		ll sum = 0;
		for(int j = K; j >= 0; j--)
		{
			if((1 << j) <= R - L + 1)
			{
				sum += st[L][j];
				L += 1 << j;
			}
		}
		return sum;
	}
}rsq;
void solve()
{
	int n, q;
	cin>>n>>q;
	ll ar[n];
	for(int i = 0; i<n; i++)
		cin>>ar[i];
	rsq.calc(n, ar);
	while(q--)
	{
		int a, b;
		cin>>a>>b;
		cout<<rsq.query(a-1, b-1)<<nl;
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


