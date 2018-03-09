#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

int main()
{
//	freopen("stdout.txt", "w", stdout);
//	freopen("stdin.txt", "r", stdin);
	
	
	int n;
	while(cin>>n && n)
	{
		priority_queue< int, vector<int>, greater<int> > Q;
		for(int i = 0; i<n; ++i)
		{
			int a;
			cin>>a;
			Q.push(a);
		}
		
		int sum = 0;
		for(int i = 1; i<n; ++i)
		{
			int a = Q.top(); Q.pop();
			int b = Q.top(); Q.pop();
			a+=b;
			sum+=a;
			Q.push(a);
		}
		
		cout<<sum<<endl;
	}
	
	
	return 0;
}