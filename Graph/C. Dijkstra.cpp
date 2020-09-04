//Problem Link: https://codeforces.com/problemset/problem/20/C
#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
using namespace std;
const long long inf = 1e18;
const ll N = 100001;
vector<pll> adj[N];
vector<ll> dis(N, inf);
ll n, m, a, b, w;
ll parnt[N];
void Dijkstra()
{
	priority_queue<pll, vector<pll>, greater<pll> > pq;
	pq.push({0,1});
	dis[1] = 0;
	
	while(!pq.empty())
	{
		ll curD = pq.top().first;
		ll curN = pq.top().second;
		pq.pop();
		
		for(pll edg : adj[curN])
		{
			if(curD + edg.second < dis[edg.first])
			{
				dis[edg.first] = curD + edg.second;
				pq.push({dis[edg.first], edg.first});
				parnt[edg.first] = curN;
			}
		}
	}
}
//Path printing
void PathPrint(ll n)
{
	if (n != 1)
		PathPrint(parnt[n]);
	cout<<n<<" ";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(NULL);
	
	cin>>n>>m;
	while(m--)
	{
		cin>>a>>b>>w;
		adj[a].push_back({b, w});
		adj[b].push_back({a, w});
	}
	Dijkstra();
	
	if(dis[n] != inf)
		PathPrint(n);
	else
		cout<<"-1";
		
	cout<<"\n";
	
	return 0;
}

