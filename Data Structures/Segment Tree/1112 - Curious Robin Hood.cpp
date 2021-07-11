/*
Problem Link: http://lightoj.com/volume_showproblem.php?problem=1112
*/
#include<bits/stdc++.h>
#define ll                      long long
#define nl                      "\n"
#define FI                      freopen("input.txt", "r", stdin);
#define FO                      freopen("output.txt", "w", stdout);
using namespace std;
 
const int N = 1e5+7;
int input[N],x;
ll segTree[4*N], ans = 0;
 
ll combine(int left, int right)
{
    return left + right;
}
 
void buildTree(int pos, int st, int en)
{
    if(st == en)
    {
        segTree[pos] = input[st];
        return;
    }
    int mid = (st + en) / 2;
    buildTree(2*pos+1, st, mid);
    buildTree(2*pos+2, mid+1, en);
    segTree[pos] = combine(segTree[2*pos+1], segTree[2*pos+2]);
}
 
void updateTree(int pos, int st, int en, int idx, int val)
{
    if(idx>en||st>idx) return;
   
    if(st == en)
    {  
        ans = segTree[pos];
        if(x == 1)
            segTree[pos] = val;
        if(x == 2)
            segTree[pos] += val;
        return;
    }
    int mid = (st + en) / 2;
    updateTree(2*pos+1, st, mid,idx,val);
    updateTree(2*pos+2, mid+1, en, idx, val);
    segTree[pos] = combine(segTree[2*pos+1], segTree[2*pos+2]);
}
ll query(int pos, int st, int en, int qst, int qen)
{
    if(qst<=st && qen>=en)
        return segTree[pos];
    if(qst>en||qen<st)
        return 0;
    int mid = (st + en)/2;
    return combine(query(2*pos+1, st, mid, qst, qen), query(2*pos+2,mid+1, en, qst, qen));
}
int main()
{
	//FI FO
    int t,casino = 0;
    scanf("%d",&t);
    while(t--)
    {
        int n,q;
        scanf("%d %d",&n,&q);
        for(int i = 0; i<n; i++)
            scanf("%d",&input[i]);
        buildTree(0,0,n-1);
        printf("Case %d:\n",++casino);
        for(int i = 1; i<=q; i++)
        {
            scanf("%d",&x);
            if(x==1)
            {
                int xx;
                scanf("%d",&xx);
                updateTree(0,0,n-1,xx,0);
                printf("%lld\n",ans);
            }
            else if(x==2)
            {
                int xx, v;
                scanf("%d %d",&xx,&v);
                updateTree(0,0,n-1,xx,v);
            }
            else
            {
                int ii,jj;
                scanf("%d %d",&ii,&jj);
                ll res = query(0,0,n-1,ii,jj);
                printf("%ld\n",res);
            }
        }
    }
    return 0;
}
