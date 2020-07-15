//Problem Link : https://www.spoj.com/problems/MPOW/
#include<bits/stdc++.h>
#define     nl            "\n"
#define     ll            long long
#define     REP(i,n)         for(int i = 1; i<=n; i++)
using namespace std;
typedef	    vector<ll>      vll;
const int N = 101;
const ll M = 1000000007;
ll ar[N][N], I[N][N];
void mul(ll A[][N], ll B[][N], int dim)
{
	ll res[dim+1][dim+1];
	REP(i, dim) REP(j, dim)
	{
		res[i][j] = 0;
		REP(k, dim)
			res[i][j] = (res[i][j] + (A[i][k] % M) * (B[k][j] % M))%M;
	}
	
	REP(i, dim) REP(j, dim) A[i][j] = res[i][j];
	
}
void power(ll A[][N], int dim, int p)
{
	REP(i, dim) REP(j, dim)
	{
		if(i == j)	I[i][j] = 1;
		else		I[i][j] = 0;
	}
//	REP(i, p)
//		mul(I, A, dim);  // Naive Approach

	while(p)
	{
		if(p&1)
			mul(I, A, dim), p--;
		else
			mul(A, A, dim), p /= 2;
	}
	REP(i, dim)  REP(j, dim) A[i][j] = I[i][j];
}
int main()
{
	int t, dim, p;
	cin>>t;
	while(t--)
	{
		cin>>dim>>p;
		REP(i, dim) REP(j, dim) cin>>ar[i][j];
		
		power(ar, dim, p);
		
		REP(i, dim)
		{
			REP(j, dim)
				cout<<ar[i][j]<<" ";
			cout<<"\n";
		}
	}	
	return 0;
}

