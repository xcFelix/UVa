//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#include <map>
#include <cstdlib>
#include <algorithm>
using namespace std;

struct P{
	int x, y;
	int sum;
	bool fire;
	P(const int &_x = 0, const int &_y = 0, const int &_sum = 0, const bool &_fire = 0)
	: x(_x), y(_y), sum(_sum), fire(_fire) {}
};

int dx[] = { 0,  0, 1, -1 };
int dy[] = { 1, -1, 0,  0 };

const int N = 1000 + 10;
char maze[N][N];
bool vis[N][N];
int n, m;
P s;

bool valid(int x, int y)
{
	return x>=1 && x<=n && y>=1 && y<=m;
}

int bfs(const vector<P>& v)
{
	memset(vis, false, sizeof(vis));
	queue<P> Q;
	for(int i = 0; i<v.size(); i++) Q.push(v[i]);
	Q.push(s);
	vis[s.x][s.y] = true;
	while(Q.size())
	{
		while(Q.size() && Q.front().fire)
		{
			P &p = Q.front(); Q.pop();
			int x = p.x;
			int y = p.y;
			int sum = p.sum;
			bool fire = p.fire;
			for(int i = 0; i<4; i++)
			{
				int _x = x+dx[i];
				int _y = y+dy[i];
				int _sum = sum+1;
				bool _fire = fire;
				if(valid(_x, _y) && maze[_x][_y]!='#' && maze[_x][_y]!='F')
				{
					maze[_x][_y]='F';
					Q.push(P(_x, _y, _sum, _fire));
				}
			}
		}
		
		while(Q.size() && !Q.front().fire)
		{
			P &p = Q.front(); Q.pop();
			int x = p.x;
			int y = p.y;
			int sum = p.sum;
			bool fire = p.fire;
			for(int i = 0; i<4; i++)
			{
				int _x = x+dx[i];
				int _y = y+dy[i];
				int _sum = sum+1;
				bool _fire = fire;
				if(!valid(_x, _y)) return _sum;
				if(valid(_x, _y) && !vis[_x][_y] && maze[_x][_y]!='#' && maze[_x][_y]!='F')
				{
					vis[_x][_y] = true;
					Q.push(P(_x, _y, _sum, _fire));
				}
			}
		}
	}
	return 0;
}

int main()
{
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	
	int T;
	cin>>T;
	while(T--)
	{
		vector<P> v;
		cin>>n>>m;
		for(int i = 1; i<=n; i++)
			for(int j = 1; j<=m; j++)
			{
				char ch;
				cin>>ch;
				maze[i][j] = ch;
				if(ch=='J')
				{
					s.x = i;
					s.y = j;
					s.sum = 0;
					s.fire = false;
				}
				if(ch=='F') v.push_back(P(i, j, 0, true));
			}
		
		int sum = bfs(v);
		if(sum) cout<<sum<<endl;
		else cout<<"IMPOSSIBLE"<<endl;
	}
	
	
	return 0;
}
