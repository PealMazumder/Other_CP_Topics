/*
	Problem Link: https://www.spoj.com/problems/HORRIBLE/
  Range Update, Range Sum Query
*/
#include<bits/stdc++.h>
#define ll 						long long
#define nl 						"\n"

using namespace std;

const int N = 1e5+7;
int input[N];
ll segTree[4*N],lazy[4*N];

// Merge Left and Right
ll combine(ll left, ll right)
{
	return left + right;
}

void buildTree(int pos, int st, int en)
{
	if(st == en)
	{
		segTree[pos] = input[st]; ///Initialize
		lazy[pos] = 0; 
		return;
	}
	
	int mid = (st+en)/2;
	buildTree(2*pos, st, mid);
	buildTree(2*pos+1, mid+1, en);
	segTree[pos] = combine(segTree[2*pos], segTree[2*pos + 1]);
	lazy[pos] = 0; ///Initialize
	
}
void propagate(int pos, int st, int en)
{
	segTree[pos] += (en-st+1)*lazy[pos];
	if(st != en)
	{
		lazy[2*pos] += lazy[pos];
		lazy[2*pos+1] += lazy[pos]; 
	}
	lazy[pos] = 0;
}
void updateTree(int pos, int st, int en,int l, int r, int value)
{
	if(lazy[pos] != 0)
		propagate(pos,st,en);
		
	if(r<st || l>en)  return;
	
	if(l<=st && en<=r) 
	{
	    lazy[pos] += value;
	    propagate(pos, st, en);
	    return;
	}
	
	int mid = (st+en)/2;
	updateTree(2*pos, st, mid,l,r,value);
	updateTree(2*pos+1, mid+1, en,l,r,value);
	segTree[pos] = combine(segTree[2*pos], segTree[2*pos + 1]);

}
ll query(int pos, int st, int en, int qst, int qen)
{
	propagate(pos, st, en);
	
	if(qst<=st && en<=qen)
		return segTree[pos];
				
	if(qen<st||qst>en) 
		return 0; //Proper Null Value
	
	int mid = (st + en)/2;
	return combine(query(2*pos, st, mid, qst, qen),query(2*pos+1, mid+1, en, qst, qen));
	
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,c;
		scanf("%d%d",&n,&c);
		buildTree(1,1,n);
		for(int i = 0;i<c;i++)
		{
			int ck;
			scanf("%d",&ck);
			if(ck)
			{
				int p,q;
				scanf("%d%d",&p,&q);
				printf("%lld\n",query(1,1,n,p,q));	
			}
			else
			{
				int p ,q,v;
				scanf("%d%d%d",&p,&q,&v);
				updateTree(1,1,n,p,q,v);
			}
		}
	}
	return 0;
}

