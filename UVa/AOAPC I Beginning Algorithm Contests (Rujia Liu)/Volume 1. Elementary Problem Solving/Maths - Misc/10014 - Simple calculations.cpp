#include <iostream>
#include <vector>
#include <numeric>
#include <cstdio>
using namespace std;

int main()	//1-n迭代相加两轮
{
	//freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
	//freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	
	int N;
	cin>>N;
	while(N--)
	{
		int n;
		cin>>n;
		
		double a, b;
		vector<double> v;
		cin>>a>>b;
		for(int i = 0; i<n; ++i)
		{
			double t;
			cin>>t;
			t*=n-i; 
			v.push_back(t);
		}
		
		printf("%.2lf\n", (n*a+b-2*accumulate(v.begin(), v.end(), .0))/(n+1));
		if(N) cout<<endl;
	}

	
	return 0;
}