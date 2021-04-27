//Problem Link: https://lightoj.com/problem/substring-frequency
#include<bits/stdc++.h>
#define nl "\n"
#define ll long long
#define ULL unsigned long long
#define pb push_back
#define sz(x) (int)x.size()
#define    all(p) p.begin(),p.end()
using namespace std;
int casino = 0;
const int N = 1000002;
const int M = 44444;
const ULL hs = 3797;
ULL F[N], H[N];
void solve()
{
    int an, bn;
    string a, b;
    cin>>a>>b;
    an = sz(a);
    bn = sz(b);
    ULL bHash = 0;
    H[0] = 0; for(int i = 1; i <= an; i++) H[i] = H[i - 1] * hs + a[i-1];
    for(int i = 1; i <= bn; i++) bHash = bHash * hs + b[i-1];
    int cnt = 0;

    for(int i = 1; i + bn - 1<=an; i++)
    {
        ULL ahash = H[i + bn - 1] - F[bn] * H[i - 1];
        if(ahash == bHash) cnt++;
    }
    cout<<"Case "<<++casino<<": "<<cnt<<nl;
}
int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(NULL);
    F[0] = 1; for(int i = 1; i < N; i++) F[i] = F[i - 1] * hs; // keeping the powers pre-calculated
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}


