#include<bits/stdc++.h>
#define	ll	long long
#define	pb	push_back
#define	sz(v)	(int)v.size()
#define	nl	"\n"
using namespace std;
const ll P = 998244353;
const ll N = 300003;
ll F[N];
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
		
	ll q;
	cin>>q;
	ll n, r;
	while(q--)
	{
		cin>>n>>r;
		cout<<nCr(n, r)<<nl;
	}
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


