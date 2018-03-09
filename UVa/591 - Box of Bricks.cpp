#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main()
{
	//freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
	//freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	
	int sum_case = 0;
	int n;
	while(cin>>n && n)
	{
		vector<int> v;
		int t;
		for(int i = 0; i<n; ++i)
		{
			cin>>t;
			v.push_back(t);
		}
		
		int ave = accumulate(v.begin(), v.end(), 0)/n;
		int sum = 0;
		for(int i = 0; i<n; ++i)
		{
			sum+=max(v[i], ave)-min(v[i], ave);
		}
		
		cout<<"Set #"<<++sum_case<<endl;
		cout<<"The minimum number of moves is "<<sum/2<<'.'<<endl<<endl;
	}

	
	return 0;
}