#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 1;
double logg[N]; ll casino = 0;
void precal()
{
	for(int i = 1; i<N; i++)
		logg[i] = logg[i-1] + log(i); 
}
void solve()
{
	int n, b;
	scanf("%d %d",&n,&b);
	
	ll ans = logg[n] / log(b) + 1;
	printf("Case %lld: %lld\n",++casino, ans); 	
}

int main()
{
	precal();
	int t;
	scanf("%d",&t);
	while(t--)
	{
		solve();
	}
	return 0;
}
