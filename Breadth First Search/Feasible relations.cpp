/*
  Problem Link: https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/feasible-relations/
*/
#include<bits/stdc++.h>
#define		fast			ios::sync_with_stdio(false);cin.tie(0);cout.tie(NULL);
#define		rep(i,n)		for(int i = 1; i<=n; i++)
#define		all(p)			p.begin(),p.end()
#define		mem(ar,val)		memset(ar, val, sizeof(ar))
#define		sz(c)			(int)c.size()
#define		pb(x)			push_back(x)
#define		mkp(x,y)		make_pair(x,y)
#define 	deb			cout<<"hehehe\n"
#define		ff			first
#define		ss			second
#define 	pf 			printf
#define 	sf 			scanf
#define		ll			long long
#define		pii			pair<int, int>
#define 	pll			pair<ll, ll>
#define 	vll			vector<long long>
#define 	vi			vector<int>
#define		nl			"\n"
#define		pnl			cout<<"\n"
#define 	total_bit(a)		__builtin_popcount(a)
#define 	UNIQUE(a)		sort(all(a)); a.erase(unique(all(a)), a.end())
#define		FI			freopen("input.txt", "r", stdin);
#define 	FO			freopen("output.txt", "w", stdout);
using namespace std;
const double pi = acos(-1.0);
const int INF = 0x7f7f7f7f;
const int N = 1e6 + 1;
vector<int> adj[N];
vector<bool> vis(N);
int dis[N],cc[N];
int val = 0;
void bfs(int x)
{
	// cout<<src<<" ";
	queue <int> q;
	vis[x] = true;
    cc[x] = ++val;
	// dis[x] = 0;
	q.push(x);
	while(!q.empty())
	{
		int cur = q.front();
		q.pop();

		for(int child : adj[cur])
		{
			if(!vis[child])
			{
                cc[child] = val;
				vis[child] = true;
				// dis[child] = dis[cur]+1;
				q.push(child);
				// cout<<child<<" ";
			}
		}
	}
}
int main()
{
    fast
	int t;
    cin>>t;
    while (t--)
    {
        val = 0;
        vector<pair<int, int> > rel;
        int n,k;
        cin>>n>>k;
        for(int i = 0; i<=n; i++)
        {
            adj[i].clear();
            vis[i] = false;
            cc[i] = 0;
        }
        
        string ans = "YES";
        for(int i = 0; i<k; i++)
        {
            int x,y;
            string r;
            cin>>x>>r>>y;
            if(r == "=")
                adj[x].pb(y),adj[y].pb(x);
            else
                rel.push_back({x,y});
            
        }
        for(int i = 1; i<=n; i++)
            if(!vis[i]) bfs(i);

        for(int i = 0; i<sz(rel); i++)
        {
            int a = rel[i].first;
            int b = rel[i].second;
            if(cc[a] == cc[b])
            {
                ans = "NO";
                break;
            }
        }
        cout<<ans<<nl;
    }
    return 0;
}

