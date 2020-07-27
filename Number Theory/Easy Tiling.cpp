//Problem Link: https://www.codechef.com/problems/TILE
#include<bits/stdc++.h>
#define	mod	1000000007
#define	ll	long long
#define	pb	push_back
#define	nl	"\n"
#define	REP(i,n)	for(int i = 1; i<=n; i++)
using namespace std;
ll I[3][3], T[3][3];
ll n;
ll MatrixMul(ll A[][3], ll B[][3], ll dim)
{
	ll res[dim+1][dim + 1];
	REP(i, dim) REP(j, dim)
	{
		res[i][j] = 0;
		REP(k, dim)
		{
			ll x = ((A[i][k] %mod) * (B[j][k] % mod)) % mod;
			res[i][j] = (res[i][j] + x) % mod;
		}
	}
	REP(i, dim) REP(j, dim) A[i][j] = res[i][j];
}

void solve()
{
	cin>>n;
	REP(i, 2) REP(j, 2)
	{
		if(i == j) I[i][j] = 1;
		else I[i][j] = 0;
	}
	T[1][1] = 0;
	T[1][2] = T[2][1] = T[2][2] = 1;
	n--;
	while(n)
	{
		if(n & 1)
			MatrixMul(I, T, 2), n--;
		else
			MatrixMul(T, T, 2), n /= 2;	
	}	
	ll ans = (I[1][1] + I[2][1] * 2) % mod;
	cout<<ans<<nl;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(NULL);
	
	int t;
	cin>>t;
	while(t--)
	    solve();
	    
	return 0;
}

