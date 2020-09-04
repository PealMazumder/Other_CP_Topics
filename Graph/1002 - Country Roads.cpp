#include<bits/stdc++.h>
#define	inf	1000000000
using namespace std;
vector<pair<int, int> > adj[501];
int n, m, a, b, w, s, casino = 0;
void DijkstraAlgorithm()
{
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	vector<int> dis(n+1, inf);
	pq.push({0,s});
	dis[s] = 0;
	
	while(!pq.empty())
	{
		int curD = pq.top().first; 
		int curN = pq.top().second;
		pq.pop();
		
		for(pair<int, int> edg : adj[curN])
		{
			int curmx = max(edg.second, curD);
			if(curmx < dis[edg.first])
			{
				dis[edg.first] = curmx;
				pq.push({dis[edg.first], edg.first});
			}
		}
	}
	printf("Case %d:\n", ++casino);
	for(int i = 0; i<n; i++)
	{
		if(dis[i] == inf)
			printf("Impossible\n");
		else	printf("%d\n",dis[i]);	
	}
}
int main()
{
//	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d", &n, &m);
		for(int i = 0; i<=500; i++)
			adj[i].clear();
		for(int i = 0; i < m; i++)
		{
			scanf("%d %d %d", &a, &b, &w);
			adj[a].push_back({b, w});
			adj[b].push_back({a, w});
		}
		scanf("%d", &s);
		
		DijkstraAlgorithm();
	}
	return 0;
}
