#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <cctype>
#include <algorithm>
#include <limits>
#include <sstream>
using namespace std;

struct N{
	int x;
	int y;
	int d; //此点出的方向
	N(const int _x = -1, const int _y = -1, const int _d = -1)
	: x(_x), y(_y), d(_d) {}
};

const int MAXN = 10;
vector< vector<int> > maze[MAXN][MAXN]; //不同进入方向的所有出方向 
map<char, int> mp;
bool vis[MAXN][MAXN][4]; //是否从某个方向出去过
int dx[] = { -1,  0, 1, 0 };
int dy[] = {  0, -1, 0, 1 };


void print(vector<N> &path)
{
	for(int i = 0; i<path.size(); i++)
	{
		N &n = path[i];
		cout<<"("<<n.x<<","<<n.y<<")"<<" ";
	}
	cout<<endl;
}


N s;
N t;
vector<N> bfs()
{
	queue< vector<N> > Q;
	vector<N> S;
	S.push_back(s);
	Q.push(S);
	while(Q.size())
	{
		vector<N> path = Q.front(); Q.pop();
		N n = path.back();
//		print(path);
		int x = n.x;
		int y = n.y;
		int d = n.d;
//		cout<<x<<" "<<y<<" "<<d<<endl;
		if(vis[x][y][d]) continue;
		vis[x][y][d] = true;
		
//		if(x==1 && y==1) cout<<d<<endl;
		int _x = x + dx[d];
		int _y = y + dy[d];
		
		if(_x==t.x && _y==t.y)
		{
			path.push_back(t);
			return path;
		}
		
//		cout<<_x<<" "<<_y<<"   :";
		vector<int> &v = maze[_x][_y][d]; //v[i] := 出去的方向
//		cout<<_x<<" "<<_y<<" "<<d<<endl;
//		cout<<v[0]<<endl;
		for(int i = 0; i<v.size(); i++)
		{
//			if(_x==1 && _y==1) cout<<v[i]<<endl;
			path.push_back(N(_x, _y, v[i]));
//			cout<<"("<<_x<<","<<_y<<")"<<" "<<v[i]<<" ";
			Q.push(path);
			path.pop_back();
//			cout<<Q.size();
		}
//		cout<<endl; 
//		cout<<Q.size();
//		cout<<endl;
	}
	
	return vector<N>();
}

void init()
{
	memset(vis, false, sizeof(vis));
	for(int i = 0; i<MAXN; i++)
		for(int j = 0; j<MAXN; j++)
		{
			maze[i][j].clear();
			maze[i][j].resize(4);
		}
}

int main()
{
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
	
	
	mp['N'] = 0;
	mp['W'] = 1;
	mp['S'] = 2;
	mp['E'] = 3;
	
	string name;
	while(cin>>name && name!="END")
	{
		init();
		cout<<name<<endl;
		
		char ch;
		cin>>s.x>>s.y;
		cin>>ch;
		s.d = mp[ch];
		cin>>t.x>>t.y;
		
		int x;
		int y;
		while(cin>>x && x)
		{
			cin>>y;
			string s;
			while(cin>>s && s[0]!='*')
			{
				int d = mp[s[0]];
				vector<int> &v = maze[x][y][d];
				for(int i = 1; i<s.size(); i++)
				{
					if(s[i]=='F') v.push_back(d);
					else if(s[i]=='L') v.push_back((d+1)%4);
					else v.push_back((d-1+4)%4);
				}
			}
		}
		
//		for(int i = 1; i<=3; i++)
//			for(int j = 1; j<=3; j++)
//			{
//				for(int d = 0; d<4; d++)
//				{
//					cout<<i<<" "<<j<<" "<<d<<"  :";
//					vector<int> &v = maze[i][j][d];
//					for(int k = 0; k<v.size(); k++) cout<<v[k]<<" ";
//					cout<<endl;
//				}
//				cout<<endl;
//			}
		
		
		vector<N> path = bfs();
		if(path.size()==0) cout<<"  No Solution Possible"<<endl;
		else
		{
			for(int i = 0; i<path.size(); i++)
			{
				N &n = path[i];
				if(i%10==0) cout<<"  "<<"("<<n.x<<","<<n.y<<")";
				else cout<<" "<<"("<<n.x<<","<<n.y<<")";
				if(i%10==9 && i!=path.size()-1) cout<<endl;
			}
			cout<<endl;
		}
	}
	
	
	return 0;
}