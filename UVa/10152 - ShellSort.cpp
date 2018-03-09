#include <iostream>
#include <vector>
using namespace std;

int main()
{
	//freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
	//freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);

	
	int n;
	cin>>n;
	while(n--)
	{
		int m;
		cin>>m;
		cin.get();
		
		vector<string> src, des;
		for(int i = 0; i<m; ++i)
		{
			string s;
			getline(cin, s);
			src.push_back(s);
		}
		
		for(int i = 0; i<m; ++i)
		{
			string s;
			getline(cin, s);
			des.push_back(s);
		}
		
		int index = m-1;
		for(int i = m-1; i>=0; --i)
		{
			if(src[i]==des[index]) --index;
		}
		
		for(; index>=0; --index) cout<<des[index]<<endl;
		cout<<endl;
	}
	
	
	return 0;
}