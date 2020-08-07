//Problem Link: https://codeforces.com/contest/1399/problem/D
#include<bits/stdc++.h>
#define	mod	1000000007
#define	ll	long long
#define	pb	push_back
#define	sz(v)	(int)v.size()
#define	nl	"\n"
#define	REP(i,n)	for(int i = 1; i<=n; i++)
using namespace std;
const ll INF = 0x7f7f7f7f;
bool ck, ck1, ck2;
void solve()
{
	int n, m, x, y, sum, i, j, k, a, b, c, tm, val, cnt, res, mn, mx, l ,r;
	string s;
	cin>>n>>s;
	int ans[n];
	stack<int> z, o;
	mx = 0;
	for(i = 0; i<n; i++)
	{
		if(s[i] == '0')
		{
			if(o.empty())
			{
				ans[i] = ++mx;
				z.push(mx);
			}
			else
			{
				tm = o.top();
				o.pop();
				ans[i] = tm;
				z.push(tm);
			}
		}
		else if(s[i] == '1')
		{
			if(z.empty())
			{
				ans[i] = ++mx;
				o.push(mx);
			}
			else
			{
				tm = z.top();
				z.pop();
				ans[i] = tm;
				o.push(tm);
			}
		}
	}
	cout<<mx<<nl;
	for(i = 0; i<n; i++)
		cout<<ans[i]<<" ";
	cout<<nl;
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
