//Problem Link: https://codeforces.com/gym/102694/problem/B
#include<bits/stdc++.h>
#define         nl                  "\n"
#define         mod                 1000000007
#define         sz(c)               (int)c.size()
#define         pb                  push_back
#define         ff                  first
#define         ss                  second
#define         ll                  long long
#define         all(p)              p.begin(),p.end()
using namespace std;
const ll INF = 1000000000000000000;
const int N = 300005;
vector<int> adj[N], dis(N);
int diam = 0, nd = 0;
void dfs(int n, int d, int par)
{
    if(dis[n] < d) dis[n] = d;

    if(d > diam)
        diam = d, nd = n;

    for(int child : adj[n])
        if(child != par)
            dfs(child, d + 1, n);
}
void solve()
{
    int n, i, a, b;
    cin>>n;
    for (i = 1; i<n; i++)
    {
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    if(n == 1){
        cout<<"1\n"; return;
    }
    dfs(a, 0, -1);

    dfs(nd, 0, -1);

    dfs(nd, 0, -1);

    for(int i = 1; i <= n; i++)
    {
        if(dis[i] == diam) cout<<diam + 1<<nl;
        else cout<<diam<<nl;
    }
}
int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(NULL);
//    int t;
//    cin>>t;
//    while(t--)
        solve();
    return 0;
}
