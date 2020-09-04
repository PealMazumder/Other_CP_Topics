//Problem Link: http://lightoj.com/volume_showproblem.php?problem=1019
#include<bits/stdc++.h>
#define	pb	push_back
using namespace std;
typedef pair<int, int> pii;
const int inf = 1e9;
const int N = 101;
vector<pii> adj[N];
int casino = 0;
void Dijkstra(int n)
{
	priority_queue<pii, vector<pii>, greater<pii> > pq;
	vector<int> dis(N, inf);
	dis[1] = 0;
	pq.push({0,1});
	
	while(!pq.empty())
	{
		int curD = pq.top().first;
		int curN = pq.top().second;
		pq.pop();
		for(pii edg : adj[curN])
		{
			if(curD + edg.second < dis[edg.first])
			{
				dis[edg.first] = curD + edg.second;
				pq.push({dis[edg.first], edg.first});
			}
		}
	}
	printf("Case %d: ", ++casino);
	if(dis[n] == inf)
		printf("Impossible\n");
	else
		printf("%d\n", dis[n]);
}
void solve()
{
	int n, m, u, v, w;
	scanf("%d%d",&n,&m);
	while(m--)
	{
		scanf("%d%d%d", &u, &v, &w);
		adj[u].pb({v,w});
		adj[v].pb({u,w});
	}
	Dijkstra(n);
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		for(int i = 0; i<101; i++)
			adj[i].clear();
		solve();
	}

	return 0;
}

