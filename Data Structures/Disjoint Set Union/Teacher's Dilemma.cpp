#include<bits/stdc++.h>
#define ll						long long
#define nl						"\n"
using namespace std;
const int INF = 0x7f7f7f7f;
const int N = 1e5+1;
const ll modulo = 1e9 + 7;
int parent[N],size[N];
void make_set(int v)
{
	parent[v] = v;
	size[v] = 1;
}
int find(int v)
{
	if(parent[v] == v)
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
		if(size[a]<size[b])
		{
			swap(a,b);
		}	
		parent[b] = a;
		size[a] += size[b];
		size[b] = -1;
	}	
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i = 0; i<m; i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		if(size[u]==0)
			make_set(u);
		if(size[v] == 0)
			make_set(v);
		Union(u,v);
	}
	ll ans = 1;
	for(int i = 1; i <= n; i++)
	{
	//	cout<<size[i]<<nl;
		if(size[i] > 0)
			ans =(ans*size[i]) % modulo;
	}
	cout<<ans<<nl;
    return 0;
}

