#include <iostream>
using namespace std;

int main()
{
	//freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
	//freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	
	char c;
	while(cin>>c)
	{
		if(c=='_') continue;
		if(c=='|')
		{
			cin.get();
			cin.get(c);
			int index = 6;
			int sum = 0;
			while(c!='|')
			{
				if(c=='.')
				{
					cin.get(c);
					continue;
				}
				if(c=='o') sum+=1<<index;
				--index;
				cin.get(c);
			}
			cout<<(char)sum;
		}
	}
	
	
	return 0;
}