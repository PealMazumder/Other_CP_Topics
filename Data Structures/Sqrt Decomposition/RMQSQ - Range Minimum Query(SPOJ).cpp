/*
  Problem Link: https://www.spoj.com/status/ns=25734926
  Tutorials on Sqrt Decomposition: https://www.youtube.com/watch?v=o7278rPg_9I
*/

#include<bits/stdc++.h>
using namespace std;
const int INF = 0x7f7f7f7f;
const int M = 1e9 + 7;
const int N = 1e5+2;
const int b = 320; //sqrt(N)
int ar[N],block[b];

void update(int val, int idx, int bsz)
{
	int id = idx / bsz;
	block[id] = min(block[id],val);
}
int query(int l, int r, int bsz)
{
	int lb = l / bsz;
	int rb = r / bsz;
	int ans = INF;
	if(lb == rb)
	{
		for(int i = l; i<=r; i++)
			ans = min(ans, ar[i]);
		return ans;
	}
	
	for(int i = l; i<(lb + 1) * bsz; i++)
		ans = min(ans, ar[i]);
		
	for(int i = lb+1; i<rb; i++)
		ans = min(ans, block[i]);
		
	for(int i = rb * bsz; i <= r; i++)
		ans  = min(ans, ar[i]);
	
	return ans;
}
int main()
{
	int n;
	scanf("%d",&n);
	int bsz = sqrt(n);
	
	for(int i = 0; i<=bsz; i++)
		block[i] = INF;
		
	for(int i = 0; i<n; i++)
	{
		scanf("%d",&ar[i]);
		update(ar[i], i,bsz);
	}
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		int ans = query(a,b,bsz);
		printf("%d\n",ans);
	}
    return 0;
}

