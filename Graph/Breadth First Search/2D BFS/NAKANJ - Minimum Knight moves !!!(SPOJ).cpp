/*
  Problem Link: https://www.spoj.com/problems/NAKANJ/
  Tutorials on 2D BFS:	http://www.shafaetsplanet.com/?p=604
  						http://www.shafaetsplanet.com/planetcoding/?p=1448
*/

#include<bits/stdc++.h>
#define pb(x)					push_back(x)
#define ll						long long
#define ff						first
#define ss						second
#define nl						"\n"
#define pii						pair<int, int>
using namespace std;
const int N = 65;
ll fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knight's Move
ll fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knight's Move

int mov[N][N];
bool vis[N][N];

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
		for(int k = 0; k<8; k++)
		{
			int tx = v.ff + fx[k];
			int ty = v.ss + fy[k];
			if(tx>=1 and tx<=8 and ty>=1 and ty<=8 and vis[tx][ty]==0 )
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
	map<char, int> mp = {{'a',1},{'b',2},{'c',3},{'d',4},{'e',5},
							{'f',6},{'g',7},{'h',8}};
	int t;
	scanf("%d",&t);
	//cout<<mp['a']<<nl;
	while(t--)
	{
		int y1, y2,x1,x2;
		for(int i = 1; i<=8; i++)
		{
			for(int j = 1; j<=8; j++)
			{
				vis[i][j] = false;
				mov[i][j] = 0;
			}
		}
		char a, b;
//		printf("cholche\n");
		scanf(" %c %d %c %d",&a,&y1,&b,&y2);
		//cout<<a<<" "<<b<<nl;
		x1 = mp[a]; x2 = mp[b];
		//cout<<x1<<" "<<x2<<nl;
		bfs(x1,y1);
		
		printf("%d\n",mov[x2][y2]);
	}
    return 0;
}


