#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
using namespace std;

const int N = 75;

bool arr[N*3+9][N*3+9];

int dx[] = {0,  0, 1, -1};
int dy[] = {1, -1, 0,  0};

int a, b;

int dfs(int x, int y)
{
	if(x<0 || x>=a || y<0 || y>=b || arr[x][y]) return 0;
	else
	{
		int sum = 1;
		arr[x][y] = true;
		for(int i = 0; i<4; ++i) sum+=dfs(x+dx[i], y+dy[i]);
		return sum;
	}
}

int main()
{
//	freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
//	freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	
	int sum_case = 0;
	while(cin>>b>>a && b)
	{
		memset(arr, 0, sizeof(arr));
		
		for(int i = 0; i<a; ++i)
		{
			for(int j = 0; j<b; ++j)
			{
				char ch;
				cin>>ch;
				
				if(ch=='\\')
				{
					arr[i*3][j*3]=arr[i*3+1][j*3+1]=arr[i*3+2][j*3+2]=true;
				}
				else
				{
					arr[i*3+2][j*3]=arr[i*3+1][j*3+1]=arr[i*3][j*3+2]=true;
				}
			}
		}
		
		a*=3;
		b*=3;
		
		for(int i = 0; i<b; ++i)
		{
			if(arr[0][i]==false) dfs(0, i);
			if(arr[a-1][i]==false) dfs(a-1, i);
		}
		
		for(int i = 0; i<a; ++i)
		{
			if(arr[i][0]==false) dfs(i, 0);
			if(arr[i][b-1]==false) dfs(i, b-1);
		}
		
		int sum = 0;
		int max_len = 0;
		for(int i = 0; i<a; ++i)
		{
			for(int j = 0; j<b; ++j)
			{
				if(arr[i][j]==false)
				{
					++sum;
					max_len = max(max_len, dfs(i, j));
				}
			}
		}
		
		cout<<"Maze #"<<++sum_case<<':'<<endl;
		if(sum) cout<<sum<<" Cycles; the longest has length "<<max_len/3<<'.'<<endl<<endl;
		else cout<<"There are no cycles."<<endl<<endl;
	}
	
	
	return 0;
}