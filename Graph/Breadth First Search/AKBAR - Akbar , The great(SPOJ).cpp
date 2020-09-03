/*
  Problem Link: https://www.spoj.com/problems/AKBAR/
  Tutorials on BFS: https://cp-algorithms.com/graph/breadth-first-search.html
*/

#include<bits/stdc++.h>
#define pb(x)					push_back(x)
#define ll						long long
#define nl						"\n"
using namespace std;
const int N = 1e6+7;
vector<int> adj[N];
vector<bool> vis(N);
vector<int> lvl(N);
using namespace std;
bool bfs(int n, int s)
{
//	cout<<n<<" ";
	bool ck = false;
	queue <int> q;
	if(!vis[n]) ck = true;
	vis[n] = true;
	lvl[n] = 0;
	q.push(n);
	
	while(!q.empty())
	{
		int v = q.front();
		q.pop();

		for(int u : adj[v])
		{
			if(!vis[u] && lvl[v]+1<=s)
			{
				vis[u] = true;
				lvl[u] = lvl[v]+1;
				q.push(u);
				ck = true;
			}
		}
	}
	if(ck) return true;
	else return false;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,r,m;
		scanf("%d %d %d",&n,&r,&m);
		for(int i = 0; i<=n; i++)
		{
			adj[i].clear();
			vis[i] = false;
			lvl[i] = 0;
		}
		for(int i = 0; i<r; i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			adj[u].pb(v);
			adj[v].pb(u);
		}
		bool ck = true;
		for(int i = 0; i<m; i++)
		{
			int k,s;
			scanf("%d%d",&k,&s);
			if(vis[k] && s == 0)
				ck = false;
			else if(!vis[k] && s == 0) vis[k] = true;
			else
			{
				bool ck1 = bfs(k,s);
			//	cout<<"ck1 "<<ck1<<nl;
				if(ck1 == false) ck = false;
			}	
		}
		for(int i = 1; i<=n; i++)
		{
			if(vis[i] == false) ck = false;
		}
		if(ck == false)
			printf("No\n");
		else
			printf("Yes\n");
	}
    return 0;
}
