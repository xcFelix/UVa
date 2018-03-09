#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 9;
int dis[N][N];

int dx[] = { 2,  2, 1,  1, -1, -1, -2, -2 };
int dy[] = { 1, -1, 2, -2,  2, -2,  1, -1 };

struct T{
	int x, y;
	
	T(const int& _x, const int& _y)
	: x(_x), y(_y) {}
	
	bool valid() const
	{
		return x>=1 && x<=8 && y>=1 && y<=8;
	}
	
	bool operator==(const T& t) const
	{
		return x==t.x && y==t.y;
	}
};

int bfs(const T& src, const T& des)
{
	dis[src.x][src.y] = 0;
	
	queue<T> Q;
	Q.push(src);
	
	int min_n = 1<<20;
	while(Q.size())
	{
		T t = Q.front(); Q.pop();
		
		for(int i = 0; i<8; ++i)
		{
			T _t(t.x+dx[i], t.y+dy[i]);
			if(_t==des) min_n = min(min_n, dis[t.x][t.y]+1);
			else if(_t.valid() && dis[_t.x][_t.y]<0)
			{
				Q.push(_t);
				dis[_t.x][_t.y] = dis[t.x][t.y]+1;
			}
		}
	}
	
	return min_n;
}

int main()
{
//	freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
//	freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	
	string s1, s2;
	while(cin>>s1>>s2)
	{
		memset(dis, -1, sizeof(dis));
		
		T src(s1[0]-'a'+1, s1[1]-'0');
		T des(s2[0]-'a'+1, s2[1]-'0');
		
		if(s1==s2) cout<<"To get from "<<s1<<" to "<<s2<<" takes 0 knight moves."<<endl;
		else cout<<"To get from "<<s1<<" to "<<s2<<" takes "<<bfs(src, des)<<" knight moves."<<endl;
	}
	
	
	return 0;
}