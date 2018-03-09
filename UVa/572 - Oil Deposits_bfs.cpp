#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 109;
char G[N][N];

int dx[] = { 0,  0, 1, -1, 1,  1, -1, -1 };
int dy[] = { 1, -1, 0,  0, 1, -1,  1, -1 };

int m, n;

struct T{
	int x, y;
	
	T(const int& _x, const int& _y)
	: x(_x), y(_y) {}
	
	bool valid()
	{
		return x>=1 && x<=m && y>=1 && y<=n;
	}
};

void bfs(int x, int y)
{
	G[x][y] = '*';
	queue<T> Q;
	Q.push(T(x, y));
	
	while(Q.size())
	{
		T t = Q.front(); Q.pop();
		
		for(int i = 0; i<8; ++i)
		{
			T _t(t.x+dx[i], t.y+dy[i]);
			
			if(_t.valid() && G[_t.x][_t.y]=='@')
			{
				G[_t.x][_t.y] = '*';
				Q.push(_t);
			}
		}
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
					bfs(i, j);
					++sum;
				}
			}
		}
	
		cout<<sum<<endl;
	}
	
	
	return 0;
}