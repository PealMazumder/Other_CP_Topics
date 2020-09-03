/*
  Problem Link: https://www.spoj.com/problems/PPATH/
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
const int M = 1e9 + 7;
const int N = 1e6+1;
vector<int> adj[N];
vector<bool> vis(N);
vector<int> primes;
int dis[N];
bool isPrime(int n)
{
    for(int i = 2; i*i<=n; i++)
        if(n % i == 0) return false;
    return true;
}
bool isValid(int a, int b)
{
    int cnt = 0;
    while (a>0)
    {
        if((a % 10) != (b % 10)) cnt++;
        a /= 10, b /= 10;
    }
    if(cnt == 1) return true;
    else return false;
}
void buildGraph()
{
    for(int i = 1000; i<10000; i++)
        if(isPrime(i))
            primes.pb(i);
    for(int i = 0; i<sz(primes); i++)
        for(int j = i+1; j<sz(primes); j++)
        {
            int a = primes[i];
            int b = primes[j];
            if(isValid(a,b))
            {
                adj[a].pb(b), adj[b].pb(a);
            }
        }
}
void bfs(int src)
{
	queue <int> q;
	vis[src] = true;
    dis[src] = 0;
	q.push(src);
	while(!q.empty())
	{
		int cur = q.front();
		q.pop();

		for(int child : adj[cur])
		{
			if(!vis[child])
			{
				vis[child] = true;
                dis[child] = dis[cur]+1;
				q.push(child);
			}
		}
	}
}
int main()
{
	int t;
    scanf("%d",&t);
    buildGraph();
    while(t--)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        for (int i = 1000; i <10000; i++)
        {
            dis[i] = -1;
            vis[i] = false;
        }
        bfs(a);
        if(dis[b] == -1) printf("Impossible\n");
        else printf("%d\n",dis[b]);
    }
    return 0;
}
