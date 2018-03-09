#include <iostream>
#include <string>
using namespace std;

int arr[6][6] = { {1, 2, 3, 4, 5, 6},
				  {6, 5, 3, 4, 2, 1},
				  {4, 2, 1, 6, 5, 3},
				  {3, 5, 1, 6, 2, 4},
				  {5, 1, 3, 4, 6, 2},
				  {2, 6, 3, 4, 1, 5},
				};

int main()
{
	//freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
	//freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	
	string s;
	while(getline(cin, s))
	{
		string s1(s, 0, 6);
		string s2(s, 6, 6);
		string t(6, ' ');
		
		bool ok = false;
		for(int i = 0; i<6; ++i)
		{
			for(int j = 0; j<6; ++j)
			{
				t[j] = s2[arr[i][j]-1];
			}
			
			if(s1[0]==t[0] && s1[5]==t[5])
			{
				for(int j = 0; j<4; ++j)
				{
					int temp = t[1];
					t[1] = t[3];
					t[3] = t[4];
					t[4] = t[2];
					t[2] = temp;
					
					if(s1==t)
					{
						ok = true;
						break;
					}
				}
			}
			if(ok) break;
		}
		
		if(ok) cout<<"TRUE"<<endl;
		else cout<<"FALSE"<<endl;
	}
	
	
	return 0;
}