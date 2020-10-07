///Problem Link: https://toph.co/p/life-of-phi
#include<bits/stdc++.h>
#define	ll	long long
#define	pb	push_back
#define	sz(v)	(int)v.size()
#define	nl	"\n"
using namespace std;
const ll N = 1000002;
unsigned ll phi[N];
void precal()
{
	for(ll i = 1; i<N; i++)
		phi[i] = i;
	for(ll i = 2; i<N; i++)
	{
		if(phi[i] == i)
			for(ll j = i; j<N; j += i)
				phi[j] -= (phi[j]/i);
	}
}
void solve()
{
	ll n;
	scanf("%lld",&n);
	ll ans = (n*(n-1))/2 - (phi[n] *n)/2;
	printf("%llu\n",ans);
	
}
int main()
{
	precal();
	int t;
	scanf("%d",&t);
	while(t--)
	    solve();

	return 0;
}


