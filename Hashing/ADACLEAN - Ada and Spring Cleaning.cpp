//Problem Link: https://www.spoj.com/problems/ADACLEAN/
#include<bits/stdc++.h>
#define nl "\n"
#define ll long long
#define ULL unsigned long long
#define pb push_back
#define sz(x) (int)x.size()
#define    all(p) p.begin(),p.end()
using namespace std;
int casino = 0;
const int N = 100006;
const int M = 44444;
const ULL hs = 3797;
ULL F[N];
void solve()
{
    ULL H[N];
    char in[N];
    int n, k;
    scanf("%d%d%s",&n, &k, in + 1); // 1 indexing
    H[0] = 0; for(int i = 1; i <= n; i++) H[i] = H[i - 1] * hs + in[i];
    unordered_set<ULL> st;
    for(int i = 1; i + k - 1 <=n; i++)
    {
        ULL hash_val = H[i + k - 1] - F[k] * H[i - 1];
        st.insert(hash_val);
    }

    printf("%d\n", sz(st));
}
int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    ios::sync_with_stdio(false);
//    cin.tie(0);cout.tie(NULL);
    F[0] = 1; for(int i = 1; i < N; i++) F[i] = F[i - 1] * hs; // keeping the powers pre-calculated
    int t;
    scanf("%d", &t);
    while(t--)
        solve();
    return 0;
}
