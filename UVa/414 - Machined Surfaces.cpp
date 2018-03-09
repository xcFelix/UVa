#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main()
{
	//freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
	//freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);


	int n;
	while(cin>>n && n)
	{
		cin.get();
		int min_n = 25;
		vector<int> v;
		for(int i = 0; i<n; ++i)
		{
			string s;
			getline(cin, s);
			int t = count(s.begin(), s.end(), ' ');
			v.push_back(t);
			min_n = min(min_n, t);
		}
		
		cout<<accumulate(v.begin(), v.end(), 0)-min_n*v.size()<<endl;
	}
	
	return 0;
}