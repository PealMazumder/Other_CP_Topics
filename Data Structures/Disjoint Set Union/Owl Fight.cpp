/*
	Problem link: shorturl.at/lmnPS
*/
#include<bits/stdc++.h>
#define ll						long long
#define nl						"\n"
using namespace std;
const int INF = 0x7f7f7f7f;
const int N = 1e5+1;
int parent[N];
void make_set(int v)
{
	parent[v] = v;
}
int find(int v)
{
	if(v == parent[v])
		return v;
	else
		return parent[v] = find(parent[v]);
}

void Union(int a, int b)
{
	a = find(a);
	b = find(b);
	
	if(a != b)
	{
		if(a<b)
			swap(a,b);
		parent[b] = a;
	}
}
int main()
{
	int n,m,q;
	scanf("%d%d",&n,&m);
	for(int i = 1; i<=n; i++) make_set(i);
	for(int i = 0; i<m; i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);	
		Union(u,v);
	}
	scanf("%d",&q);
	for(int i = 0;i<q; i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		int a = find(u);
		int b = find(v);
		
		if(a == b)
			printf("TIE\n");
		else
		{
			if(a>b)
				printf("%d\n",u);
			else
				printf("%d\n",v);
		}
	}
    return 0;
}

