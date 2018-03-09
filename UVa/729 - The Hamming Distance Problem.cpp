#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 19;
int arr[N];

void print(int hi)
{
	for(int i = 1; i<=hi; ++i) cout<<arr[i];
	cout<<endl;
}

int main()
{
//	freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
//	freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	
	int n;
	cin>>n;
	while(n--)
	{
		memset(arr, 0, sizeof(arr));
		
		int a, b;
		cin>>a>>b;
		
		for(int i = a-b+1; i<=a; ++i) arr[i] = 1;
		print(a);
		
		while(next_permutation(arr+1, arr+1+a)) print(a);
		if(n) cout<<endl;
	}
	
	
	return 0;
}