//Problem Link: http://lightoj.com/volume_showproblem.php?problem=1109
#include<bits/stdc++.h>
using namespace std;
int casino = 0;
struct Div
{
	int d, val;
}ar[1000];
bool comp(Div a, Div b)
{
    if(a.d == b.d)
		return a.val > b.val;
    return a.d < b.d;
}

int NOD(int n)
{
	int ret = 1;
	for(int i = 2; i*i<=n; i++)
	{
		if(n%i == 0)
		{
			int cnt = 1;
			while(n%i == 0)
			{
				cnt++;
				n/=i;
			}
			ret *= cnt;
		}
	}
	if(n>1)
		ret *= 2;
	return ret;
}
void PreCompute()
{
	for(int i = 1, nod; i<=1000; i++)
	{
		nod = NOD(i);
		ar[i-1].d = nod;
		ar[i-1].val = i;
	}
	sort(ar, ar + 1000, comp);
}
int main()
{	
	PreCompute();
	int t, n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		printf("Case %d: ", ++casino);
		cout<<ar[n-1].val<<"\n";
	}

	return 0;
}

