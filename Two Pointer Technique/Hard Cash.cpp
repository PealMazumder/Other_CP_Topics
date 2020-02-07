///https://www.codechef.com/FEB20B/problems/CASH
#include<bits/stdc++.h>
#define all(p)						p.begin(),p.end()
#define mem(ar, val)					memset(ar, val, sizeof(ar))
#define sz(c)						(int)c.size()
#define pb(x)						push_back(x)
#define ll						long long
#define nl						"\n"
#define MAX(a, b)					((a) > (b) ? (a) : (b))
#define MIN(a, b)					((a) < (b) ? (a) : (b))
using namespace std;
const int INF = 0x7f7f7f7f;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		int a[n+2];
		for(int i =0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		int l=0,r=n-1;
		ll out = 0, need = 0; 
		while(l<=r)
		{
		    if(a[r]%k!=0)
			{
				ll tem = a[r]/k + 1;
				need = tem*k - a[r];
				if(out>=need)
				{
					out -= need;
					need = 0;
					r--;
				}
			}
			else if(a[r]%k==0)
				r--;
				
			if(a[l]%k!=0 && need>0)
			{
				ll tem = a[l]/k;
				out += a[l] - tem*k;
				l++;
			}
			else if(a[l]%k==0)
				l++;
		}
		out = out%k;
		printf("%lld\n",out);
	}

    return 0;
}

