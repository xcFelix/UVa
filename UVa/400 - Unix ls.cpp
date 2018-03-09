#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	//freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
	//freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	
	int n;
	while(cin>>n)
	{
		for(int i = 0; i<60; ++i) cout<<'-'; cout<<endl;
		
		vector<string> v;
		int max_size = -1;
		for(int i = 0; i<n; ++i)
		{
			string s;
			cin>>s;
			v.push_back(s);
			max_size = max(max_size, (int)s.size());
		}
		
		max_size+=2;
		sort(v.begin(), v.end());
		for(int i = 0; i<n; ++i)
		{
			v[i].resize(max_size, ' ');
		}
		
		int per_line = 60/max_size;
		if(per_line==0) per_line = 1;
		int lines = v.size()/per_line;
		if(v.size()%per_line) ++lines;
		
		for(int i = 0; i<lines; ++i)
		{
			for(int j = 0; j<per_line; ++j)
			{
				if(i+j*lines<v.size()) cout<<v[i+j*lines];
			}
			cout<<endl;
		}
	}
	
	
	return 0;
}