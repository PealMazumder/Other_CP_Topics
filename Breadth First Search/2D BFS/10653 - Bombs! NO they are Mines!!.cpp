/*
  Problem Link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1594
  Tutorials on :
*/

#include<bits/stdc++.h>
#define pb(x)					push_back(x)
#define ll						long long
#define ff						first
#define ss						second
#define nl						"\n"
#define pii						pair<int, int>
#define FI						freopen("input.txt", "r", stdin);
#define FO						freopen("output.txt", "w", stdout);
using namespace std;
const int N =  1007;
int mov[N][N];
bool vis[N][N],bombs[N][N];
ll fx[]={ 1, -1,  0,  0};
ll fy[]={ 0,  0,  1, -1};
int r,c;
void bfs(int x, int y)
{
//	cout<<n<<" ";
	queue <pair<int, int> > q;
	vis[x][y] = true;
	q.push(pii(x,y));
	while(!q.empty())
	{
		pii v = q.front();
		q.pop();
		for(int k = 0; k<4; k++)
		{
			int tx = v.ff + fx[k];
			int ty = v.ss + fy[k];
			if(tx>=0 and tx<r and ty>=0 and ty<c and vis[tx][ty]==0 and bombs[tx][ty]==false)
			{
				vis[tx][ty] = true;
				mov[tx][ty] = mov[v.ff][v.ss] + 1;
				q.push(pii(tx,ty));
			}
		}
	}
}
int main()
{	
//	FI
//	FO
	while(scanf("%d%d",&r,&c),(r|c))
	{
		for(int i = 0; i<=r; i++)
		{
			for(int j = 0; j<=c; j++)
			{
				vis[i][j] = false;
				mov[i][j] = 0;
				bombs[i][j] = false;
			}
		}
		int R;
		scanf("%d",&R);
		for(int i =0; i<R; i++)
		{
			int a,b;
			scanf("%d %d",&a,&b);
			for(int j = 0; j<b; j++)
			{
				int rn;
				scanf("%d",&rn);
				bombs[a][rn] = true;
			}
		}
		int x1,y1,x2,y2;
		scanf(" %d %d %d %d",&x1,&y1,&x2,&y2);
//		cout<<x2<<y2<<nl;
		bfs(x1,y1);
//		for(int i = 0; i<=x2; i++)
//		{
//			for(int j = 0; j<=y2; j++)
//				cout<<mov[i][j]<<" ";
//			cout<<nl;
//		}
		printf("%d\n",mov[x2][y2]);
	}
    return 0;
}



