#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 12;
char arr[N][N];
int num[N][N];
bool vis[N][N];

int main()
{
//	freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
//	freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	
	int sum_case = 0;
	int c, r;
	while(cin>>r>>c)
	{
		if(sum_case) cout<<endl;
		
		memset(arr, 0, sizeof(arr));
		memset(num, 0, sizeof(num));
		memset(vis, false, sizeof(vis));
		
		for(int i = 1; i<=r; ++i)
		{
			for(int j = 1; j<=c; ++j) cin>>arr[i][j];
		}
		
		int n = 1;
		for(int i = 1; i<=r; ++i)
		{
			for(int j = 1; j<=c; ++j)
			{
				if(arr[i][j]!='*' && (i==1 || j==1 || arr[i-1][j]=='*' || arr[i][j-1]=='*')) num[i][j] = n++;
			}
		}
		
		printf("puzzle #%d:\n", ++sum_case);
		cout<<"Across"<<endl;
		
		for(int i = 1; i<=r; ++i)
		{
			for(int j = 1; j<=c; ++j)
			{
				int _j = j;
				if(!vis[i][_j] && arr[i][_j]!='*')
				{
					printf("%3d.", num[i][j]);
					while(arr[i][_j]!='*' && _j<=c)
					{
						cout<<arr[i][_j];
						vis[i][_j] = true;
						++_j;
					}
					
					cout<<endl;
				}
			}
		}
		
		cout<<"Down"<<endl;
		memset(vis, false, sizeof(vis));
		
		for(int i = 1; i<=r; ++i)
		{
			for(int j = 1; j<=c; ++j)
			{
				int _i = i;
				if(!vis[_i][j] && arr[_i][j]!='*')
				{
					printf("%3d.", num[i][j]);
					while(arr[_i][j]!='*' && _i<=r)
					{
						cout<<arr[_i][j];
						vis[_i][j] = true;
						++_i;
					}
					
					cout<<endl;
				}
			}
		}
	}
	
	
	return 0;
}