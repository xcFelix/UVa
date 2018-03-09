#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int N = 3009;

int arr[N];

int main()
{
//	freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
//	freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	
	int a, b;
	while(cin>>a>>b)
	{
		memset(arr, -1, sizeof(arr));
		
		int _a = a;
		
		int c;
		if(_a>=b)
		{
			c = _a/b;
			_a%=b;
		}
		else c = 0;
		
		int index = 0;
		vector<int> v;
		
		arr[_a] = index++;
		
		while(true)
		{
			_a*=10;
			v.push_back(_a/b);
			_a%=b;
			
			if(arr[_a]!=-1) break;
			else arr[_a] = index++;
		}
		
		cout<<a<<'/'<<b<<" = ";
		cout<<c<<'.';
		for(int i = 0; i<arr[_a]; ++i) cout<<v[i];
		cout<<'(';
		for(int i = arr[_a]; i<v.size() && i-arr[_a]<50; ++i) cout<<v[i];
		if(v.size()-arr[_a]>=50) cout<<"...";
		cout<<')'<<endl;
		
		cout<<"   "<<v.size()-arr[_a]<<" = number of digits in repeating cycle"<<endl;
		cout<<endl;
	}
	
	
	return 0;
}