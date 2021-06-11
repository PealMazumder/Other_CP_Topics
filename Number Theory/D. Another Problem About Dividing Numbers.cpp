//Problem Link: http://codeforces.com/contest/1538/problem/D
#include<bits/stdc++.h>
#define nl "\n"
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define    all(p) p.begin(),p.end()
using namespace std;
unordered_map<ll, int> ma;
const ll N = 1e5;
vector<ll> prime;
bool vis[N];
void sieve()
{
    for(ll i = 3; i*i<=N; i+=2)
    {
        if(!vis[i])
        {
            for(ll j = i*i; j<=N; j += 2*i)
                vis[j] = true;
        }
    }
    prime.push_back(2LL);
    for(ll i = 3; i<N; i += 2)
        if(!vis[i]) prime.push_back(i);
}
vector<ll> primeFact(ll n)
{
	vector<ll> pf;
	ll root = sqrt(n);
	for(ll i = 0; i<sz(prime) && prime[i] <= root; i++)
	{
		if(!(n % prime[i]))
		{
			while(!(n % prime[i]))
			{
				n /= prime[i];
				pf.push_back(prime[i]);
			}
			root = sqrt(n);
		}
	}
	if(n>1)
		pf.push_back(n);

	return pf;
}
void solve()
{
    ll a, b, k;
    cin>>a>>b>>k;
    vector<ll> x = primeFact(a);
    vector<ll> y = primeFact(b);
    ll cntSame = 0, tot = sz(x) + sz(y);
    unordered_map<ll, int> mx, my;
    for(auto it : x) mx[it]++;
    for(auto it : y) my[it]++;
    for(auto it : mx)
    {
        a = mx[it.first];
        b = my[it.first];
        if(a > b) swap(a, b);
        cntSame += a;
    }
    if(k == 1)
    {
        if(sz(x) == sz(y) || sz(x) != cntSame && sz(y) != cntSame)
            cout<<"NO\n";
        else cout<<"YES\n";
    }
    else if(k > tot)  cout<<"NO\n";
    else cout<<"YES\n";
}
int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(NULL);
    sieve();
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}


