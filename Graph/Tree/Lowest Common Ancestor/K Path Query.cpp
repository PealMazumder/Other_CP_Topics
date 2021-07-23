//Problem Link: https://www.codechef.com/JULY21B/problems/KPATHQRY
#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 1e5+2;
vector<int> adj[N];
int L[N], parent[N];
int P[N][19];
void dfs(int node, int d, int par)
{
    L[node] = d, P[node][0] = par;
    parent[node] = par;
    for(int child : adj[node])
        if(child != par)
            dfs(child, d+1, node);
}
void init()
{
    memset (P, -1, sizeof(P));
    dfs(1, 0, -1);
    for(int j = 1; j < 19; j++)
    {

        for(int i = 1; i < N; i++)
        {
            if(P[i][j-1] != -1)
                P[i][j] = P[P[i][j-1]][j-1];
        }
    }
}
int LCA(int a, int b)
{
    if(L[a] > L[b]) swap(a, b);
    int d = L[b] - L[a];
    while(d > 0)
    {
        int i = log2(d);
        b = P[b][i];
        d -= (1 << i);
    }
    if(a == b) return a;
    for(int i = 18; i>=0; i--)
        if(P[a][i] != -1 && P[a][i] != P[b][i])
            a = P[a][i], b = P[b][i];
    return P[a][0];
}
void solve()
{
    int n, i, j, k, q, a, b;
    cin>>n;
    for(i = 0; i<=n; i++)
    {
        adj[i].clear();
        L[i] = 0;
        parent[i] = 0;
    }
    for(i = 1; i<n; i++)
    {
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    init();
    cin>>q;
    while(q--)
    {
        cin>>k;

        vector<int> ar(k);
        bool ck[N] = {0};

        int mxLevel = -1, val = ar[0];

        for(i = 0; i<k; i++)
        {
            cin>>ar[i];
            if(mxLevel < L[ar[i]])
                val = ar[i], mxLevel = L[ar[i]];
        }

        int val1 = -1, lca;

        for(i = 0; i<k; i++)
        {
            if(ar[i] == val) continue;
            lca = LCA(val, ar[i]);
            if(lca != ar[i])
            {
                val1 = ar[i];
                break;
            }
        }
        if(val1 == -1)
        {
            cout<<"YES\n";
            continue;
        }

        while(true)
        {
            ck[val] = 1;
            if(val == lca) break;
            val = parent[val];
        }
        int tm = val1;
        for(i = 0; i<k; i++)
        {
            if(ck[ar[i]] == 0 && L[tm] < L[ar[i]])
                tm = ar[i];
        }

        while(true)
        {
            ck[tm] = 1;
            if(tm == 1 || tm == lca) break;
            tm = parent[tm];
        }
        bool ck1 = 0;
        for(i = 0; i<k; i++)
        {
            if(ck[ar[i]] == 0)
            {
                cout<<"NO\n";
                ck1 = 1;
                break;
            }
        }
        if(!ck1) cout<<"YES\n";
    }

}
int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}


