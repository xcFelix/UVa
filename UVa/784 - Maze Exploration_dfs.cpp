#include <iostream>
#include <cstring>
#include <cstdio> 
using namespace std;

const int N = 39;
const int M = 89;

char arr[N][M];

int dx[] = { 0,  0, 1, -1 };
int dy[] = { 1, -1, 0,  0 };

void dfs(int x, int y)
{
	arr[x][y] = '#';
	
	for(int i = 0; i<4; ++i)
	{
		int _x = x+dx[i];
		int _y = y+dy[i];
		
		if(arr[_x][_y]==' ') dfs(_x, _y);
	}
}

int main()
{
//	freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
//	freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	
	int n;
	cin>>n;
	cin.get();
	while(n--)
	{
		int row = 0;
		while(gets(arr[row]) && arr[row][0]!='_') row++;
		
		int column = 0;
		for(row = 0; arr[row][0]; ++row)
		{
			for(column = 0; arr[row][column] && arr[row][column]!='*'; ++column);
			if(arr[row][column]=='*') break;
		}
		
		dfs(row, column);
		
		for(int i = 0; ; ++i)
		{
			puts(arr[i]);
			if(arr[i][0]=='_') break;
		}
	}
	
	
	return 0;
}