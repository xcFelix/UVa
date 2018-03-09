#include <iostream>
#include <cstring>
using namespace std;

const int N = 109;
char G[N][N];

int dx[] = { 0,  0, 1, -1, 1,  1, -1, -1 };
int dy[] = { 1, -1, 0,  0, 1, -1,  1, -1 };

int m, n;

void dfs(int x, int y)
{
	G[x][y] = '*';
	
	for(int i = 0; i<8; ++i)
	{
		int _x = x+dx[i];
		int _y = y+dy[i];
		
		if(_x>=1 && _x<=m && _y>=1 && _y<=n && G[_x][_y]=='@') dfs(_x, _y);
	}
}

int main()
{
//	freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
//	freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	
	while(cin>>m>>n && m)
	{
		for(int i = 1; i<=m; ++i)
		{
			for(int j = 1; j<=n; ++j) cin>>G[i][j];
		}
	
		int sum = 0;
		for(int i = 1; i<=m; ++i)
		{
			for(int j = 1; j<=n; ++j)
			{
				if(G[i][j]=='@')
				{
					dfs(i, j);
					++sum;
				}
			}
		}
	
		cout<<sum<<endl;
	}
	
	
	return 0;
}
