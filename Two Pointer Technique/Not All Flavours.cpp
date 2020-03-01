/*
	Problem Link: https://www.codechef.com/problems/NOTALLFL
*/
#include<bits/stdc++.h>
#define ll						long long
#define nl						"\n"
#define MAX(a, b)					((a) > (b) ? (a) : (b))
#define MIN(a, b)					((a) < (b) ? (a) : (b))
using namespace std;
const int INF = 0x7f7f7f7f;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		int ar[n],ckk[k+1];
		
		for(int i = 0;i<n;i++)
			cin>>ar[i];
			
		for(int i = 1;i<=k; i++) ckk[i] = 0;
		
		int l=0,r = 0;
		ll cnt = 0, mx = 0,cntk = 0,ck  = 0;
		while(r<n)
		{
			if(ckk[ar[r]] == 0)
				cntk++;
			
			ckk[ar[r]]++;
			
			if(ckk[ar[l]]>1)
			{
				ckk[ar[l]]--;
				l++;
			}
			
			if(cntk == k)
			{
				mx = MAX(mx,cnt);
				while(ckk[ar[l]]>1)
				{
					ckk[ar[l]]--;
					l++;	
				}
				ckk[ar[l]] = 0;
				cnt -= (l-ck);
				cntk--;
				l++;
				ck = l;
				
			}
			else
				cnt++;
			r++;
		}
		
		mx = MAX(cnt,mx);
		cout<<mx<<nl;
	}
	
    return 0;
}


