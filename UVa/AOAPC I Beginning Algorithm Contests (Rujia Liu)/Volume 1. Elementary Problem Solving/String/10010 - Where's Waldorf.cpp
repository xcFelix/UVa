#include <iostream>
#include <string>
#include <cctype>
using namespace std;

const int MAX_N = 59;
char arr[MAX_N][MAX_N];

int dx[] = { 0,  0, -1, 1, -1,  1, -1, 1 };
int dy[] = { 1, -1,  0, 0, -1, -1,  1, 1 };
int m, n;

bool is_find(int x, int y, const string& s)
{
	for(int i = 0; i<8; ++i)
	{
		int index = 0;
		for(int _x = x, _y = y; _x<m&&_x>=0&&_y<n&&_y>=0&&index!=s.size(); _x+=dx[i], _y+=dy[i])
		{
			if(arr[_x][_y]!=s[index]) break;  
			++index; //´íÎóÌ«Òþ±ÎÁË£¬É÷ÓÃ -- if(arr[_x][_y]!=s[index++]) break;
		}
		if(index==s.size()) return true;
	}
	
	return false;
}

int main()
{
	//freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
	//freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	
	int N;
	cin>>N;
	while(N--)
	{
		cin>>m>>n;
		for(int i = 0; i<m; ++i)
		{
			for(int j = 0; j<n; ++j)
			{
				char c;
				cin>>c;
				arr[i][j] = tolower(c);
			}
		}
		
		int M;
		cin>>M;
		while(M--)
		{
			string s;
			cin>>s;
			for(int i = 0; i<s.size(); ++i) s[i] = tolower(s[i]);
			
			bool _find = false;
			for(int i = 0; i<m; ++i)
			{
				for(int j = 0; j<n; ++j)
				{
					if(arr[i][j]==s[0])
					if(is_find(i, j, s))
					{
						cout<<++i<<' '<<++j<<endl;
						_find = true;
						break;
					}
				}
				if(_find) break;
			}
		}
		
		if(N) cout<<endl;
	}
	
	
	return 0;
}