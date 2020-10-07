//Problem Link: http://lightoj.com/volume_showproblem.php?problem=1007
#include<bits/stdc++.h>
#define	ll	long long
#define	pb	push_back
#define	sz(v)	(int)v.size()
#define	nl	"\n"
using namespace std;
const ll N = 5000002;
unsigned ll phi[N];
int casino = 0;
void precal()
{
	for(ll i = 0; i<N; i++)
		phi[i] = i;
	for(ll i = 2; i<N; i++)
	{
		if(phi[i] == i)
			for(ll j = i; j<N; j += i)
				phi[j] -= (phi[j]/i);
	}
	
	for(ll i = 2; i<N; i++)
		phi[i] = phi[i-1] + (phi[i] * phi[i]);
}
void solve()
{
	ll a, b;
	scanf("%lld%lld",&a, &b);
	unsigned ll ans = phi[b] - phi[a-1];
	printf("Case %d: %llu\n", ++casino, ans);
}
int main()
{
//	freopen("output.txt","w", stdout);
	precal();
	ll t;
	scanf("%lld",&t);
	while(t--)
	    solve();

	return 0;
}


