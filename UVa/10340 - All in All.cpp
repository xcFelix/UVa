#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
//	freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
//	freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	
	string src, des;
	while(cin>>des>>src)
	{
		bool ok = false;
		for(int i = 0, j = 0; i<src.size() && j<des.size(); ++i)
		{
			if(src[i]==des[j])
			{
				if(++j==des.size())
				{
					ok = true;
					break;
				}
			}
		}
		
		if(ok) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	
	
	return 0;
}