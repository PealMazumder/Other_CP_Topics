//Problem Link: https://www.spoj.com/problems/SUB_PROB/
#include<bits/stdc++.h>
#define nl  "\n"
#define ULL unsigned long long
#define ll  long long
#define pb  push_back
#define sz(x)   (int)x.size()
#define     all(p) p.begin(),p.end()
using namespace std;
int casino = 0;
const int N = 100006;
const int M = 44444;
const int QN = 2006;
const ULL hs = 3797;

ULL F[N], H[N];
char in[N];
int n;

ULL seg(int x, int y) {
    return H[y] - F[y - x + 1] * H[x - 1];
}

void solve()
{
    F[0] = 1; for(int i = 1; i < N; i++) F[i] = F[i - 1] * hs; // keeping the powers pre-calculated
    scanf("%s", in + 1); // 1 indexing
    n = strlen(in + 1);

    H[0] = 0; for(int i = 1; i <= n; i++) H[i] = H[i - 1] * hs + in[i];
    int q;
    scanf("%d", &q);
    unordered_map<int, bool> mp;
    set<ULL> st;
    while(q--)
    {
        char qs[QN];
        scanf("%s", qs + 1);
        int S = strlen(qs + 1);
        ULL qs_hash = 0;
        for(int i = 1; i <= S; i++) qs_hash = qs_hash * hs + qs[i];
        bool ck = 0;
        if(mp[S])
        {
            if(st.find(qs_hash) != st.end())
                printf("Y\n");
            else printf("N\n");
            continue;
        }
        mp[S] = 1;
//        cout<<qs_hash<<" "<<seg(1, 2)<<nl;
        for(int i = 1; i + S - 1 <=n; i++)
        {
            ULL curr_h = seg(i, i + S - 1);
            st.insert(curr_h);
            if(qs_hash == curr_h)
                ck = 1;
        }
        if(!ck)
            printf("N\n");
        else printf("Y\n");
    }

}
int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    ios::sync_with_stdio(false);
//    cin.tie(0);cout.tie(NULL);
//    int t;
//    cin>>t;
//    while(t--)
        solve();
    return 0;
}
