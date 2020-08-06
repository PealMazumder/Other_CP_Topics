//Problem Link:http://www.lightoj.com/volume_showproblem.php?problem=1067
#include<bits/stdc++.h>
#define	mod	1000003
#define	ll	long long
#define	pb	push_back
#define	sz(v)	(int)v.size()
#define	nl	"\n"
#define	REP(i,n)	for(int i = 1; i<=n; i++)
using namespace std;
const int N = 1000003; 
int casino = 0;
int fac[N];
void preCal()
{
	fac[0] = fac[1] = 1;
	for(int i = 2; i<N; i++)
	{
		fac[i] = (fac[i-1] * 1LL * i) % mod;
	}
}
int ModInv(int b, int p)
{
	int res = 1;
	while(p)
	{
		if(p & 1)
			res = (res * 1LL * b) % mod;
		
		b = (b * 1LL * b) % mod;
		p /= 2;	
		 
	}
	return res;
}
void solve()
{
	int n, k;
	scanf("%d%d",&n,&k);
	int d = (fac[k] * 1LL * fac[n-k]) % mod;
	int ans = (fac[n] * 1LL* ModInv(d, mod - 2)) % mod;
	printf("Case %d: %d\n", ++casino, ans);
}
int main()
{	
	preCal();
	int t;
	scanf("%d", &t);
	while(t--)
	    solve();

	return 0;
}
