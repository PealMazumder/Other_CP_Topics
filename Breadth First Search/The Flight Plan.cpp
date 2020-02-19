/*
Problem Link: shorturl.at/iDES6
*/

#include<bits/stdc++.h>
#define all(p)					p.begin(),p.end()
#define mem(ar, val)			memset(ar, val, sizeof(ar))
#define sz(c)					(int)c.size()
#define pb(x)					push_back(x)
#define ll						long long
#define nl						"\n"
#define FI						freopen("input.txt", "r", stdin);
#define FO						freopen("output.txt", "w", stdout);
using namespace std;
const int N = 1e3+2;
vector<vector<int> > adj;
bool vis[N];
int p[N];
vector<int> ans;
void bfs(int x, int y)
{
	queue<int> q;
	q.push(x);
	vis[x] = true;
	while(!q.empty())
	{
		int v = q.front();
		q.pop();
		sort(all(adj[v]));
		for(auto it = adj[v].begin();it!= adj[v].end();it++)
		{
			if(!vis[*it])
			{
				vis[*it] = true;
				q.push(*it);
				p[*it] = v;
				if(*it == y)
				{
					ans.pb(y);
					int tem = y;   
					while(p[tem])
					{
						int pp = p[tem];
						ans.pb(pp);
						tem = pp;
					}
					return;
				}
			}
		}
	}
}
int main()
{
	int n,m,t,c;
	scanf("%d%d%d%d",&n,&m,&t,&c);
	adj.assign(N,vector<int>());
	
	while(m!=0 && m--)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		adj[u].pb(v);
		adj[v].pb(u);
		
	}
	
	int x,y;
	scanf("%d%d",&x,&y);
	if(m==0)
	{
		printf("%d\n%d\n",x,y);
		return 0;
	}
	bfs(x,y);
	printf("%d\n",ans.size());
	for(auto it = ans.rbegin();it!=ans.rend();it++)
		printf("%d ",*it);
	printf("\n");
    return 0;
}
