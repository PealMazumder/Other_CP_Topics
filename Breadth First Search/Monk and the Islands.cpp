/*
Problem Link : shorturl.at/myIJ4
*/
#include<bits/stdc++.h>
#define all(p)					p.begin(),p.end()
#define mem(ar, val)			memset(ar, val, sizeof(ar))
#define sz(c)				    (int)c.size()
#define pb(x) 					push_back(x)
using namespace std;
const int N = 1e4 + 2;
vector<vector <int> > adj;
int vis[N];
int bfs(int n)
{
	queue<int> q;
	q.push(1);
	vis[1] = 0;
	while(!q.empty())
	{
		int v = q.front();
		q.pop();

		for(auto it = adj[v].begin(); it != adj[v].end(); it++)
		{
			if(!vis[*it])
			{
				q.push(*it);
				vis[*it] = vis[v] + 1;
			}
			if(*it == n)
				return vis[*it];
		}

	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d%d",&n,&m);

		mem(vis,0);
		adj.assign(N,vector<int>());

		for(int i = 0; i < m; i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			adj[x].pb(y);
			adj[y].pb(x);
		}
		int ans = bfs(n);
		printf("%d\n",ans);
	}
    return 0;
}


