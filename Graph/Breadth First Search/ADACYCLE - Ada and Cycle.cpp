/*
  Problem Link: https://www.spoj.com/problems/ADACYCLE/
  Tutorials on :
*/

#include<bits/stdc++.h>
#define	mem(ar,val)					memset(ar, val, sizeof(ar))
#define pb(x)					push_back(x)
#define ll						long long
#define nl						"\n"
using namespace std;
const int N = 2007;
vector<int> adj[N];
bool vis[N];
int lvl[N];
int bfs(int n)
{
	mem(vis,false);
	mem(lvl,0);
//	cout<<n<<" ";
	queue <int> q;
	vis[n] = true;
	q.push(n);
	while(!q.empty())
	{
		int v = q.front();
		q.pop();

		for(int u : adj[v])
		{
			if(!vis[u])
			{
				vis[u] = true;
				lvl[u] = lvl[v]+1;
				q.push(u);
			//	cout<<u<<" ";
			}
			else if(u == n)
			{
				return lvl[v]+1;
			}
		}
	}
	return 0;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 1; i<=n; i++)
	{
		for(int j = 1; j<=n; j++)
		{
			int x;
			scanf("%d",&x);
			if(x==1)
				adj[i].push_back(j);
		}
	}
	for(int i = 1;i<=n; i++)
	{	
		int ans = bfs(i);
		if(ans == 0)
			printf("NO WAY\n");
		else
			printf("%d\n",ans);
	}
    return 0;
}
