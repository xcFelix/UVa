#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

int main()
{
//	freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
//	freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	
	int n;
	cin>>n;
	while(n--)
	{
		string src;
		
		cin>>src;
		src.resize(src.size()*2);
		
		int len = src.size()/2;
		for(int i = 0; i<len; ++i) src[i+len] = src[i];
		
		string des(src, 0, len);
		
		for(int i = 1; i<len; ++i)
		{
			if(des.compare(0, len, src, i, len)>0) des = src.substr(i, len);
		}
		
		cout<<des<<endl;
	}
	
	
	return 0;
}