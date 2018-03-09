#include <iostream>
#include <vector>
using namespace std;

int main()
{
	//freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
	//freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	
	int N;
	cin>>N;
	while(N--)
	{
		int L;
		cin>>L;
		vector<int> v;
		for(int i = 0; i<L; ++i)
		{
			int t;
			cin>>t;
			v.push_back(t);
		}
		
		int sum = 0;
		for(int i = 0; i<v.size(); ++i)
		{
			for(int j = i+1; j<v.size(); ++j)
			{
				if(v[i]>v[j]) ++sum;
			}
		}
		
		cout<<"Optimal train swapping takes "<<sum<<" swaps."<<endl;
	}
	
	
	return 0;
}