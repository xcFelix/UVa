#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	//freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
	//freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	
	int n;
	cin>>n;
	while(n)
	{
		cin.get();
		vector<string> v1, v2, v3;
		for(int i = 0; i<n; ++i)
		{
			string s;
			getline(cin, s);
			v1.push_back(s);
			getline(cin, s);
			v2.push_back(s);
		}
		
		while(!isdigit(cin.peek()))
		{
			string s;
			getline(cin, s);
			v3.push_back(s);
		}
		
		for(int i = 0; i<v3.size(); ++i)
		{
			for(int j = 0; j<v1.size(); ++j)
			{
				int index;
				while((index = v3[i].find(v1[j]))!=string::npos)
				{
					v3[i].replace(index, v1[j].size(), v2[j]);
				}
			}
		}
		
		for(int i = 0; i<v3.size(); ++i) cout<<v3[i]<<endl;
		
		cin>>n;
	}
	
	
	return 0;
}