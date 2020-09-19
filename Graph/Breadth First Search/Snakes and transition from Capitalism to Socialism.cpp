//Problem Link: https://www.codechef.com/problems/SNSOCIAL
#include<bits/stdc++.h>
#define	ll	long long
#define	pb	push_back
#define	sz(v)	(int)v.size()
#define	nl	"\n"
#define		mem(ar,val)		memset(ar, val, sizeof(ar))
using namespace std;
int fx[]={ 0,  0,  1, -1, -1,  1, -1,  1};
int fy[]={-1,  1,  0,  0,  1,  1, -1, -1};
int n, m, mx;
int ar[501][501];
int vis[501][501];
void MultisourceBFS()
{
	mem(vis, -1);
	queue<pair<int, int> > q;
	for(int i = 0; i<n; i++)
	{
		for(int j = 0; j<m; j++)
			if(ar[i][j] == mx)
			{
				q.push({i,j});
				vis[i][j] = 0;
			}
	}
	int ans = 0;
	while(!q.empty())
	{
		int a = q.front().first;
		int b = q.front().second;
		q.pop();
		for(int i = 0; i<8; i++)
		{
			if(a+fx[i] >= 0 && b+fy[i] >= 0 && a+fx[i] < n && b+fy[i] < m)
			{
				if(vis[a+fx[i]][b+fy[i]] == -1)
				{
					vis[a+fx[i]][b+fy[i]] = vis[a][b] + 1;
					q.push({a+fx[i], b+fy[i]});	
					ans = max(ans, vis[a+fx[i]][b+fy[i]]);
				}
			}
		}
	}
	cout<<ans<<nl;
}
void solve()
{
	mx = INT_MIN;
	cin>>n>>m;
	
	for(int i = 0; i<n; i++)
	{
		for(int j = 0; j<m; j++)
		{
			cin>>ar[i][j];
			mx = max(mx, ar[i][j]);
		}
	}
	MultisourceBFS();
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

