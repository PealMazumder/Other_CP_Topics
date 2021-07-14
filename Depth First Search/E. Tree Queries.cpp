//Problem Link: https://codeforces.com/contest/1328/problem/E
#include<bits/stdc++.h>
#define         nl                  "\n"
#define         mod                 1000000007
#define         sz(c)               (int)c.size()
#define         pb                  push_back
#define         ff                  first
#define         ss                  second
#define         ll                  long long
#define         all(p)              p.begin(),p.end()
#define         UNIQUE(a)           sort(all(a)); a.erase(unique(all(a)), a.end())
using namespace std;
const ll INF = 1000000000000000000;
const int N = 200005;
vector<int> adj[N];
int L[N], par[N], in[N], out[N];
int timer = 0;
void dfs(int node, int pa, int d)
{
    L[node] = d, par[node] = pa, in[node] = ++timer;
    for(int child : adj[node])
        if(child != pa)
            dfs(child, node, d+1);
    out[node] = ++timer;
}
bool cmp(int a, int b)
{
    return L[a] < L[b];
}
void solve()
{
    int n, m, u, v;
    cin>>n>>m;

    for(int i = 1; i<n; i++)
    {
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1, 1, 0);
    while(m--)
    {
        int k;
        cin>>k;
        vector<int> ar(k);
        for(int i = 0; i<k; i++)
        {
            cin>>ar[i];
            ar[i] = par[ar[i]];
        }
        UNIQUE(ar);
        sort(all(ar), cmp);
        bool ck = 0;
        int pre = ar[0];
        for(int i = 1; i<sz(ar); i++)
        {
            if(in[pre] < in[ar[i]] && out[ar[i]] < out[pre]);
            else
            {
                cout<<"NO\n";
                ck = 1;
                break;
            }
            pre = ar[i];
        }
        if(!ck)cout<<"YES\n";
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
