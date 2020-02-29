/*
	Problem Link: shorturl.at/twKMX
	Relevent blog: http://www.shafaetsplanet.com/?p=1557
*/
#include<bits/stdc++.h>
#define ll 						long long
#define nl 						"\n"
using namespace std;

const int N = 1e5+7;
const int mx = 1e6;
int n,q;
int input[N];
int segTree[4*N];
int combine(int left, int right)
{
	return (left < right) ? left : right;
}
void buildTree(int pos, int st, int en)
{
	if(st == en)
	{
		segTree[pos] = input[st];
		return;
	}

	int mid = (st+en)/2;
	buildTree(2*pos, st, mid);
	buildTree(2*pos+1, mid+1, en);
	segTree[pos] = combine(segTree[2*pos], segTree[2*pos + 1]);

}
int query(int pos, int st, int en, int qst, int qen)
{
	if(qst<=st && en<=qen)
		return segTree[pos];
	if(qen<st||qst>en)
		return mx;

	int mid = (st + en)/2;
	return combine(query(2*pos, st, mid, qst, qen),query(2*pos+1, mid+1, en, qst, qen));

}
int main()
{
    int t,casino = 0;
    scanf("%d",&t);
    while(t--)
    {
    	scanf("%d %d",&n,&q);
    	for(int i = 1; i<=n; i++)
    		scanf("%d",&input[i]);
		buildTree(1, 1, n);
		printf("Case %d:\n",++casino);

		for(int i = 1; i<=q; i++)
		{
			int qst, qen;
			scanf("%d %d",&qst,&qen);

			int ans = query(1,1,n,qst,qen);
			printf("%d\n",ans);
		}

	}
	return 0;
}

