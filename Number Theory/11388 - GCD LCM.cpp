#include<bits/stdc++.h>
#define		ll			long long
#define		nl			"\n"

using namespace std;
void solve()
{
	ll g,l;
	scanf("%lld %lld",&g,&l);
	if(l%g==0)
		printf("%lld %lld\n",g,l);
	else
		printf("-1\n");
}
int main()
{
	ll t;
	scanf("%lld",&t);
	while(t--)
	{
		solve();
	}
	return 0;
}

