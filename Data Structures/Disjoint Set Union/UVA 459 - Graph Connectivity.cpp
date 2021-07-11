#include<bits/stdc++.h>
#define	fast						ios::sync_with_stdio(false);cin.tie(0);cout.tie(NULL);
#define	mem(ar,val)					memset(ar, val, sizeof(ar))
#define FI						freopen("input.txt", "r", stdin);
#define FO						freopen("output.txt", "w", stdout);
using namespace std;
const int INF = 0x7f7f7f7f;
const int N = 1e2+1;
int parent[27];
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
		parent[b] = a;
	}
}
int main()
{
//	fast
//	FI
//	FO
	int t;
	scanf("%d ",&t);
	while(t--)
	{
		mem(parent, 0);
		char L;
		scanf(" %c",&L);
		int total = L - 'A' + 1;
		for(int i = 1; i<=total; i++)
			make_set(i);
		string ar;
		cin.ignore();
		while(getline(cin, ar))
		{
			if(ar.empty()) break;
			int a = (ar[0] - 'A') + 1;
			int b = (ar[1] - 'A') + 1;
			Union(a,b);
		}
		int cc = 0;
		for(int i = 1; i<=total; i++)
			if(parent[i] == i) cc++;
		printf("%d\n",cc);
		if(t)
			printf("\n");
	}
    return 0;
}

