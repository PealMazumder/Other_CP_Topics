//Problem Link: https://codeforces.com/gym/102694/problem/C
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define nl "\n"

using namespace std;
const int N = 300005;
vector<int> adj[N];
int P[N][22];
int L[N];

void dfs(int node, int par, int d)
{
    L[node] = d, P[node][0] = par;
    for(int child : adj[node])
        if(child != par)
            dfs(child, node, d+1);
}
void init()
{
    memset(P, -1, sizeof P);
    dfs(1, -1, 0);
    for(int j = 1; j<22; j++)
        for(int i = 1; i<N; i++)
            if(P[i][j-1] != -1)
                P[i][j] = P[P[i][j-1]][j-1];
}
int LCA(int a, int b)
{
    if(L[a] > L[b]) swap(a, b);
    int d = L[b] - L[a], i;
    while(d > 0)
        i = log2(d), b = P[b][i], d -= (1 << i);

    if(a == b) return a;
    for(i = 21; i>= 0; i--)
        if(P[a][i] != -1 && P[a][i] != P[b][i])
             a = P[a][i], b = P[b][i];
    return P[a][0];
}
void solve()
{
    int n, i, j, a, b, q, u, v, c;
    cin>>n;
    for(i = 1; i<n; i++)
    {
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    init();
    cin>>q;
    while(q--)
    {
        cin>>a>>b>>c;
        int lca , left;
        lca = LCA(a, b);
        if(L[a] + L[b] - 2*L[lca] <= c)
        {
            cout<<b<<nl;
            continue;
        }
        left = L[a] - L[lca];
        if(left >= c)
        {
            while(c > 0)
                i = log2(c), a = P[a][i], c -= (1 << i);
            cout<<a<<nl;
        }
        else
        {
            c = L[b] - (c - left) - L[lca];
             while(c > 0)
                i = log2(c), b = P[b][i], c -= (1 << i);
            cout<<b<<nl;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(NULL);
//    int t;
//    cin>>t;
//    while(t--)
        solve();
}
