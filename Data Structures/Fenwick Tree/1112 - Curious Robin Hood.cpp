//Problem Link: http://lightoj.com/volume_showproblem.php?problem=1112
#include<bits/stdc++.h>
using namespace std;
const int mx = 100005;
int tree[mx], casino = 0;
int read(int idx)
{
	int sum = 0;
	while(idx > 0)
	{
		sum += tree[idx];
		idx -= (idx & -idx);
	}
	return sum;
}
void update(int idx, int val, int n)
{
	while(idx <= n)
	{
		tree[idx] += val;
		idx += (idx & -idx);
	}
}
void solve()
{
	memset(tree, 0, sizeof(tree));
	int n, q, i, j, v, task, ans, val;
	scanf("%d %d", &n, &q);
	for(i = 1; i <= n; i++)
	{
		cin>>val;
		update(i, val, n);
	}
	printf("Case %d:\n", ++casino);
	while(q--)
	{
		scanf("%d", &task);
		if(task == 1)
		{
			scanf("%d", &i);
			ans = read(i+1) - read(i);
			printf("%d\n", ans);
			update(i+1, -ans, n);
		}
		else if(task == 2)
		{
			scanf("%d %d", &i, &v);
			update(i+1, v, n);
		}
		else
		{
			scanf("%d %d", &i, &j);
			ans = read(j+1) - read(i);
			printf("%d\n", ans);
		}
	}
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	    solve();

	return 0;
}


