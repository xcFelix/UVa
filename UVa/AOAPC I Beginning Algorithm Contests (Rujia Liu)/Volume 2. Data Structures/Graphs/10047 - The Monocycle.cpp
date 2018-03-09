#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 29;
char G[N][N];
bool vis[N][N][5][4];

struct T{
	int x, y;
	int col;
	int dir;
	int sec;
	
	T(const int& _x = 0, const int& _y = 0, const int& _col = 0, const int& _dir = 0, const int& _sec = 0)
	: x(_x), y(_y), col(_col), dir(_dir), sec(_sec) {}
	
	bool operator==(const T& t) const
	{
		return x==t.x && y==t.y && col==t.col;
	}
	
	bool operator<(const T& t) const
	{
		return sec>t.sec;
	}
};

int dx[] = { -1, 0, 1,  0 };
int dy[] = {  0, 1, 0, -1 };

int bfs(const T& src, const T& des)
{
	priority_queue<T> Q;
	Q.push(src);
	vis[src.x][src.y][src.col][src.dir] = true;
	
	bool ok = false;
	int sec = 0;
	while(Q.size())
	{
		T t = Q.top(); Q.pop();
		
		int _x = t.x+dx[t.dir];
		int _y = t.y+dy[t.dir];
		int _col = (t.col+1)%5;
		int _dir = t.dir;
		int _sec = t.sec+1;
		
		if(!vis[_x][_y][_col][_dir])
		{
			vis[_x][_y][_col][_dir] = true;
			
			T _t(_x, _y, _col, _dir, _sec);
			if(_t==des)
			{
				ok = true;
				sec = _t.sec;
				break;
			}
			
			if(G[_t.x][_t.y]=='.' || G[_t.x][_t.y]=='T' || G[_t.x][_t.y]=='S') Q.push(_t);
//			×¢Òâ´Ë´¦ 
		}
		
		if(!vis[t.x][t.y][t.col][(t.dir+1)%4])
		{
			vis[t.x][t.y][t.col][(t.dir+1)%4] = true;
			Q.push(T(t.x, t.y, t.col, (t.dir+1)%4, t.sec+1));
		}
		
		if(!vis[t.x][t.y][t.col][(t.dir+3)%4])
		{
			vis[t.x][t.y][t.col][(t.dir+3)%4] = true;
			Q.push(T(t.x, t.y, t.col, (t.dir+3)%4, t.sec+1));
		}
	}
	
	if(ok) return sec;
	else return 0;
}

int main()
{
//	freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
//	freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	
	int sum_case = 0;
	int m, n;
	while(cin>>m>>n && !(m==0 && n==0))
	{
		if(sum_case) cout<<endl;
		
		memset(vis, false, sizeof(vis));
		memset(G, 0, sizeof(G));
		
		T src, des;
		for(int i = 1; i<=m; ++i)
		{
			for(int j = 1; j<=n; ++j)
			{
				cin>>G[i][j];
				
				if(G[i][j]=='S') src = T(i, j);
				if(G[i][j]=='T') des = T(i, j);
			}
		}
		
		cout<<"Case #"<<++sum_case<<endl;
		
		int sec = bfs(src, des);
		
		if(sec) cout<<"minimum time = "<<sec<<" sec"<<endl;
		else cout<<"destination not reachable"<<endl;
	}
	
	
	return 0;
}