#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

const int N = 7;
char arr[N][N];
int dx[] = { -1, 1,  0, 0 };
int dy[] = {  0, 0, -1, 1 };

int main()
{
//	freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
//	freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	
	map<char, int> mp;
	mp['A'] = 0;
	mp['B'] = 1;
	mp['L'] = 2;
	mp['R'] = 3;
	
	int sum_case = 0;
	while(cin.peek()!='Z')
	{
		if(sum_case) cout<<endl;
		
		memset(arr, 0, sizeof(arr));
		
		int x, y;
		for(int i = 1; i<=5; ++i)
		{
			for(int j = 1; j<=5; ++j)
			{
				arr[i][j] = cin.get();
				if(arr[i][j]==' ')
				{
					x = i;
					y = j;
				}
			}
			
			cin.get();
		}
		
		bool ok = true;
		char ch;
		while(cin>>ch && ch!='0')
		{
			int index = mp[ch];
			int _x = x+dx[index];
			int _y = y+dy[index];
			
			if(!arr[_x][_y])
			{
				ok = false;
				while(cin.get()!='0');
				break;
			}
			
			arr[x][y] = arr[_x][_y];
			arr[_x][_y] = ' ';
			
			x = _x;
			y = _y;
		}
		cin.get();	//for cin.peek()
		
		printf("Puzzle #%d:\n", ++sum_case);
		if(ok)
		{
			for(int i = 1; i<=5; ++i)
			{
				cout<<arr[i][1];
				for(int j = 2; j<=5; ++j)
				{
					cout<<' '<<arr[i][j];
				}
				
				cout<<endl;
			}
		}
		else cout<<"This puzzle has no final configuration."<<endl;
	}
	
	
	return 0;
}