#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 39;
int G[N][N][N];
bool vis[N][N][N];

struct T{
	int x, y, z;
	
	T(const int& _x = 0, const int& _y = 0, const int& _z = 0)
	: x(_x), y(_y), z(_z) {}
	
	bool operator==(const T& t)
	{
		return x==t.x && y==t.y && z==t.z;
	}
};

int dx[] = { 0,  0, 0,  0, 1, -1 };
int dy[] = { 0,  0, 1, -1, 0,  0 };
int dz[] = { 1, -1, 0,  0, 0,  0 };

bool bfs(const T& src, const T& des)
{
	G[src.x][src.y][src.z] = 0;
	G[des.x][des.y][des.z] = 1<<30;
	
	queue<T> Q;
	Q.push(src);
	while(Q.size())
	{
		T t = Q.front(); Q.pop();
		
		for(int i = 0; i<6; ++i)
		{
			int _x = t.x+dx[i];
			int _y = t.y+dy[i];
			int _z = t.z+dz[i];
			
			T _t(_x, _y, _z);
			
			if(_t==des) G[des.x][des.y][des.z] = min(G[t.x][t.y][t.z]+1, G[des.x][des.y][des.z]);
			else if(!vis[_x][_y][_z] && G[_x][_y][_z]=='.')
			{
				vis[_x][_y][_z] = true;
				G[_x][_y][_z] = G[t.x][t.y][t.z]+1;
				Q.push(_t);
			}
		}
	}
	
	return G[des.x][des.y][des.z]!=(1<<30);
}

int main()
{
//	freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
//	freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	
	int l, r, c;
	T src, des;
	
	while(cin>>l>>r>>c && !(l==0 && r==0 && c==0))
	{
		memset(vis, false, sizeof(vis));
		
		for(int i = 1; i<=l; ++i)
		{
			for(int j = 1; j<=r; ++j)
			{
				for(int k = 1; k<=c; ++k)
				{
					char ch;
					cin>>ch;
					
					G[i][j][k] = ch;
					if(ch=='S') src = T(i, j, k);
					if(ch=='E') des = T(i, j, k);
				}
			}
		}
		
		if(bfs(src, des)) cout<<"Escaped in "<<G[des.x][des.y][des.z]<<" minute(s)."<<endl;
		else cout<<"Trapped!"<<endl;
	}
	
	return 0;
}