//Problem Link: https://www.hackerrank.com/challenges/fibonacci-finding-easy/problem
#include<bits/stdc++.h>
#define ll long long
#define pb(x) push_back(x)
#define nl "\n"
#define     REP(i,n)         for(int i = 1; i<=n; i++)
using namespace std;
const ll M = 1000000007;
ll a, b, n;
ll I[3][3], T[3][3];
void MatrixMul(ll A[][3], ll B[][3], int dim)
{
	ll res[dim + 1][dim + 1];
	REP(i, dim) REP(j, dim)
	{
		res[i][j] = 0;
		REP(k, dim)
		{
			ll x = ((A[i][k]%  M) * (B[j][k] %  M)) %  M;
			res[i][j] = (res[i][j] + x) % M;
		}
	}
	REP(i, dim) REP(j, dim) A[i][j] = res[i][j];
}
void solve()
{
	cin>>a>>b>>n;
	REP(i, 2) REP(j, 2)
	{
		if(i == j) I[i][j] = 1;
		else I[i][j] = 0;
	}
	T[1][1] = 0;
	T[1][2] = T[2][1] = T[2][2] = 1;
	
	while(n)
	{
		if(n % 2 == 0)
			MatrixMul(T, T, 2), n /= 2;
		else
			MatrixMul(I, T, 2), n--;
	}
	ll ans = (I[1][1] * a + I[2][1] * b) % M;
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

