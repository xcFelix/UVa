#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAX_N = 109;
char arr[MAX_N][MAX_N];

int main()
{
	//freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
	//freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);


	fill(*arr, *arr+MAX_N*MAX_N, ' ');
	
	int row = 0;
	int column = -1;
	while(gets(arr[row]))
	{
		int len = strlen(arr[row]);
		arr[row++][len] = ' ';
		column = max(column, len);
	}
	
	for(int i = 0; i<column; ++i)
	{
		for(int j = row-1; j>=0; --j) cout<<arr[j][i];
		cout<<endl;
	}
	
	return 0;
}