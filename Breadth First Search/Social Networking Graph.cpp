/*
Problem Link: shorturl.at/hjHLR
*/
#include<bits/stdc++.h>
#define all(p)					p.begin(),p.end()
#define mem(ar, val)			memset(ar, val, sizeof(ar))
#define sz(c)					(int)c.size()
#define pb(x) 					push_back(x)
#define ll 						long long
#define nl 						"\n"
#define FI                      freopen("input.txt", "r", stdin);
#define FO                      freopen("output.txt", "w", stdout);
using namespace std;
const int N = 1e6;
vector<vector <int> > adj;
int vis[N];
int bfs(int s, int t)
{
	int ans = 0;
	queue<int> q;
	q.push(s);
	vis[s] = 0;
	while(!q.empty())
	{
		int v = q.front();
		q.pop();
		for(auto it = adj[v].begin(); it != adj[v].end(); it++)
		{
			if(vis[*it]== (-1))
			{
				q.push(*it);
				vis[*it] = vis[v] + 1;

				if(vis[*it] == t)
					ans++;

				if(vis[*it]>t)
					return ans;
			}
		}
	}
	return ans;
}
int main()
{
	int n,e;
	adj.assign(N,vector<int>());
	scanf("%d%d",&n,&e);

	for(int i = 1;i<=e;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		adj[u].pb(v);
		adj[v].pb(u);
	}
	int m;
	scanf("%d",&m);
	while(m--)
	{
		int s,t;
		scanf("%d%d",&s,&t);
		mem(vis,-1);
		int ans = bfs(s, t);
		printf("%d\n",ans);
	}

    return 0;
}
