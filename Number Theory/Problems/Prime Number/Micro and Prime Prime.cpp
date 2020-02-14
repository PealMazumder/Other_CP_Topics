/*
Problem Link : https://urlzs.com/iVtt5
*/
#include<bits/stdc++.h>
#define	fast						ios::sync_with_stdio(false);cin.tie(0);cout.tie(NULL);
#define all(p)						p.begin(),p.end()
#define	mem(ar,val)						memset(ar, val, sizeof(ar))
#define sz(c)						(int)c.size()
#define pb(x)						push_back(x)
#define mkp(x,y)						make_pair(x,y)
#define ff						first
#define ss						second
#define ll						long long
#define nl						"\n"
#define MAX(a, b)						((a) > (b) ? (a) : (b))
#define MIN(a, b)						((a) < (b) ? (a) : (b))
#define FI						freopen("input.txt", "r", stdin);
#define FO						freopen("output.txt", "w", stdout);
using namespace std;
const int INF = 0x7f7f7f7f;
const int N = 1e6 + 5;
int primePrime[N],prime[N];
void sieve()
{
	for(int i = 0; i < N; i++) prime[i] = 1;
	
	prime[0] = prime[1] = 0;
	
	for(int i = 4; i < N; i += 2) prime[i] = 0;
	
	int cnt = 1,cnt2 = 0;
	bool ck = false;
	for(ll i = 3; i < N; i++)
	{
		if(prime[i])
		{
			prime[i] = ++cnt;
			if(prime[prime[i]])
			{
				primePrime[i] = ++cnt2;
				ck = true;
			}
			else
			{
				primePrime[i] = cnt2;
				ck = false;
			}
			if(i*i<N)
				for(ll j = i*i; j<N; j += i)
					prime[j] = 0;
		}
		else if(ck) primePrime[i] = ++cnt2;
		else  primePrime[i] = cnt2; 
	}
	
}
int main()
{
	int t;
	scanf("%d",&t);
	sieve();
	while(t--)
	{
		int l, r;
		scanf("%d%d",&l,&r);
		//cout<<primePrime[r]<<" "<<primePrime[l]<<nl;
		int ans = primePrime[r] - primePrime[l-1];
		printf("%d\n",ans);
	}
    return 0;
}

