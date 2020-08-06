//Problem Link: http://lightoj.com/volume_showproblem.php?problem=1090
#include<bits/stdc++.h>
#define	mod	1000000007
#define	ll	long long
#define	pb	push_back
#define	sz(v)	(int)v.size()
#define	nl	"\n"
using namespace std;
int casino = 0;
int trailing_Zeros(int n, int j)
{
	int cnt = 0;
	while(n)
	{
		cnt += (n/j);
		n /= j;
	}
	return cnt;
}
int primeFact(int n, int j)
{ 
    int cnt = 0;
    if(n % j == 0)
    {
        while(n % j == 0 && n>0)
            cnt++, n /= j;   
    }
    return cnt;
}
void solve()
{
	int n, r, p, q;
	scanf("%d %d %d %d", &n, &r, &p, &q);
	
	int n2, n5, r2, r5, nr2, nr5;
	n2 = trailing_Zeros(n, 2) + primeFact(p, 2) * q;
	n5 = trailing_Zeros(n, 5) + primeFact(p, 5) * q;
	
	r2 = trailing_Zeros(r, 2);
	r5 = trailing_Zeros(r, 5);
	
	nr2 = trailing_Zeros(n-r, 2);
	nr5 = trailing_Zeros(n-r, 5);
	
	int ans = min(n2 - r2 - nr2, n5 - r5 - nr5);
	
	printf("Case %d: %d\n",++casino, ans);
}
int main()
{
//	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	    solve();

	return 0;
}

