#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	//freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
	//freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	
	int sum_case = 0;
	int n;
	while(cin>>n && n)
	{
		cout<<"Game "<<++sum_case<<':'<<endl;
		
		vector<int> v1;
		for(int i = 0; i<n; ++i)
		{
			int t;
			cin>>t;
			v1.push_back(t);
		}
		
		while(true)
		{
			vector<int> v2;
			
			for(int i = 0; i<n; ++i)
			{
				int t;
				cin>>t;
				v2.push_back(t);
			}
			if(v2[0]==0) break;
			
			int l = 0;
			for(int i = 0; i<n; ++i)
			{
				if(v1[i]==v2[i])
				{
					v2[i] = 0;
					++l;
				}
			}
			
			int r = 0;
			vector<int>::iterator it;
			for(int i = 0; i<n; ++i)
			{
				if(v2[i])
				{
					it = find(v2.begin(), v2.end(), v1[i]);
					if(it!=v2.end())
					{
						*it = 10;
						++r;
					}
				}
			}
			
			cout<<"    ("<<l<<','<<r<<')'<<endl;
		}
	}
	
	
	return 0;
}