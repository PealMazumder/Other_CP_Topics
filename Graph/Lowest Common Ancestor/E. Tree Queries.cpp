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
struct Lowest_Common_Ancestor{

    vector<int> adj[N];
    int P[N][22];
    int L[N], par[N];

    void dfs(int node, int pa, int d)
    {
        L[node] = d, par[node] = pa;
        P[node][0] = pa;
        for(int child : adj[node])
            if(child != pa)
                dfs(child, node, d+1);
    }
    void init()
    {
        memset (P, -1, sizeof(P));
        dfs(1, -1, 0);
        for(int j = 1; j < 22; j++)
        {

            for(int i = 1; i < N; i++)
            {
                if(P[i][j-1] != -1)
                    P[i][j] = P[P[i][j-1]][j-1];
            }
        }
    }
    int query(int a, int b)
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
        for(int i = 21; i>=0; i--)
            if(P[a][i] != -1 && P[a][i] != P[b][i])
                a = P[a][i], b = P[b][i];
        return P[a][0];
    }
} LCA;

void solve()
{
    int n, m, u, v;
    cin>>n>>m;

    for(int i = 1; i<n; i++)
    {
        cin>>u>>v;
        LCA.adj[u].pb(v);
        LCA.adj[v].pb(u);
    }

    LCA.init();

    while(m--)
    {
        int k;
        cin>>k;
        vector<int> ar(k);
        for(int i = 0; i<k; i++)
        {
            cin>>ar[i];
            ar[i] = LCA.par[ar[i]];
        }

        UNIQUE(ar);
        sort(all(ar),[](int a, int b){
             return LCA.L[a] > LCA.L[b];
        });

        bool ck = 0;
        for(int i = 1; i<sz(ar); i++)
        {
            if(LCA.query(ar[0], ar[i]) != ar[i])
            {
                cout<<"NO\n";
                ck = 1;
                break;
            }
        }

        if(!ck)
            cout<<"YES\n";
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
