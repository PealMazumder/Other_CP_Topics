//Problem Link: https://cses.fi/problemset/task/1712/
//Euler's Totient function: https://cp-algorithms.com/algebra/phi-function.html
#include<bits/stdc++.h>
#define nl "\n"
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define    all(p) p.begin(),p.end()
using namespace std;
const int mod = 1e9 + 7;
int m1, m2;
int phi(int n)
{
    int ans = n;
    for(int p = 2; p*p <= n; p++)
    {
        if(n % p == 0)
        {
            while(n % p == 0)
                n /= p;
            ans -= ans/p;
        }
    }
    if(n > 1) ans -= ans/n;
    return ans;
}
int power(int a, int b, int m)
{
    int res = 1;
    while(b)
    {
        if(b & 1) res = (res *1LL* a) % m, b--;
        a = (a *1LL* a) % m;
        b >>= 1;
    }
    return res;
}
void solve()
{
    int a, b, c;
    cin>>a>>b>>c;

    int bc = power(b, c % m2, m1);
    cout<<power(a, bc % m1, mod)<<nl;
}
int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(NULL);
    m1 = mod - 1;// phi(mod)
    m2 = phi(m1);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}


