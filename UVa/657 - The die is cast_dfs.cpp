#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 59;
char G[N][N];

int dx[] = { 0,  0, 1, -1 };
int dy[] = { 1, -1, 0,  0 };

void _dfs(int x, int y)
{
	G[x][y] = '*';
	
	for(int i = 0; i<4; ++i)
	{
		int _x = x+dx[i];
		int _y = y+dy[i];
		
		if(G[_x][_y]=='X') _dfs(_x, _y);
	}
}

int dfs(int x, int y)
{
	G[x][y] = '.';
	
	int sum = 0;
	for(int i = 0; i<4; ++i)
	{
		int _x = x+dx[i];
		int _y = y+dy[i];
		
		if(G[_x][_y]=='X')
		{
			++sum;
			_dfs(_x, _y);
		}
		if(G[_x][_y]=='*') sum += dfs(_x, _y);
	}
	
	return sum;
}

int main()
{
//	freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
//	freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	
	int sum_case = 0;
	int r, l;
	while(cin>>l>>r && !(r==0 && l==0))
	{
		memset(G, 0, sizeof(G));
		
		cin.get();
		for(int i = 1; i<=r; ++i) gets(G[i]+1);
		
		vector<int> v;
		for(int i = 1; i<=r; ++i)
		{
			for(int j = 1; j<=l; ++j)
			{
				if(G[i][j]=='*') v.push_back(dfs(i, j));
			}
		}
		
		cout<<"Throw "<<++sum_case<<endl;
		sort(v.begin(), v.end());
		cout<<v[0];
		for(int i = 1; i<v.size(); ++i) cout<<' '<<v[i];
		cout<<endl<<endl;
	}
	
	
	return 0;
}