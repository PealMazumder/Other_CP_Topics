//Problem Link: https://codeforces.com/contest/1420/problem/D
#include<bits/stdc++.h>
#define	ll	long long
#define	pb	push_back
#define	sz(v)	(int)v.size()
#define	nl	"\n"
using namespace std;
const ll P = 998244353;
const ll N = 300003;
ll F[N];
ll n, k, l, r;
vector<pair<ll, bool> > v;
ll power(ll a, ll n)//a^n
{
    ll ret = 1;
    while(n)
	{
        if(n&1)
			ret = (ret * a) % P;
        n /= 2;
        a = (a * a) % P;
    }
    return ret;
}
ll modInverse(ll n)
{
	return power(n, P - 2LL);
}
ll nCr(ll n, ll r)
{
	if(n < r) return 0;
	return (F[n] *  modInverse(F[r]) % P *  modInverse(F[n-r]) % P) % P; 
}
void solve()
{
	F[0] = F[1] = 1;
	for(ll i = 2; i<N; i++)
		F[i] = (F[i-1] * i) % P;
		
	
	cin>>n>>k;
	
	for(ll i = 0; i<n; i++)
	{
		cin>>l>>r;
		v.pb({l, 0});
		v.pb({r, 1});
	}
	sort(v.begin(), v.end());
	ll on = 0, ans = 0;
	for(ll i = 0; i<sz(v); i++)
	{
		if(v[i].second == 0)
		{
			if(on>=k-1)
				ans = (ans+ nCr(on, k-1)) % P;
			on++;
		}
		else on--;
	}
	cout<<ans<<nl;
}
int main()
{
//	ios::sync_with_stdio(false);
//	cin.tie(0);cout.tie(NULL);
//	int t;
//	cin>>t;
//	while(t--)
	    solve();

	return 0;
}


