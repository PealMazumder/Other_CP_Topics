//Prbolem Link: https://www.spoj.com/problems/RMQSQ/
#include<bits/stdc++.h>
#define	ll	long long
#define	pb	push_back
#define	sz(v)	(int)v.size()
#define	nl	"\n"
using namespace std;
const int mxn = 1000000;
//use zero based indexed array, [L,R] => [0,n-1]. INCLUSIVE
int logg[mxn+1];
struct RMQ {
    static const int K = 25;
    int st[mxn][K + 1];
 
    void precalcLog() {
        logg[1] = 0;
        for (int i = 2; i <= mxn; i++)
        	logg[i] = logg[i/2] + 1;
    }
    void calc(int N,int * array)  {
        for (int i = 0; i < N; i++)
            st[i][0] = array[i];
        for (int j = 1; j <= K; j++)
            for (int i = 0; i + (1 << j) <= N; i++)
                st[i][j] = min(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);
    }  
 
    int query(int L , int R) {
        int j = logg[R - L + 1];
        int minimum = min(st[L][j], st[R - (1 << j) + 1][j]);
        return minimum;
    }
} rmq;
 
void solve()
{
	int n;
	cin>>n;
	int ar[n];
	for(int i = 0; i<n; i++)
		cin>>ar[i];
	rmq.precalcLog();
	rmq.calc(n, ar);
	int q, l, r;
	cin>>q;
	while(q--)
	{
		cin>>l>>r;
		int ans = rmq.query(l, r);
		cout<<ans<<nl;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(NULL);

//	int t;
//	cin>>t;
//	while(t--)
	    solve();

	return 0;
}


