#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int M = 209;
char arr[M][M];

void dfs(int lo, int hi, int row)
{
	for(; lo<hi; ++lo)
	{
		if(arr[row][lo]!=' ' && arr[row][lo]!=0 && arr[row][lo]!='#') // !=0 -----向右多余的情况     !='#' 空树 
		{
			cout<<arr[row][lo]<<'(';
			
			if(arr[row+1][lo]=='|')
			{
				int _lo = lo;
				int _hi = lo;
				int _row = row+2;
				
				while(arr[_row][_lo]=='-') --_lo; ++_lo;
				while(arr[_row][_hi]=='-') ++_hi;
				++_row;
				
				dfs(_lo, _hi, _row);
			}
			
			cout<<')';
		}
	}
}

int main()
{
	//freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
	//freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	
	int n;
	cin>>n;
	cin.get();
	while(n--)
	{
		int row = 0;
		while(gets(arr[row]))
		{
			if(arr[row++][0]=='#') break;
		}
		
		int lo = 0;
		int hi = strlen(arr[0]);
		row = 0;
		
		cout<<'(';
		dfs(lo, hi, row);
		cout<<')'<<endl;
		
		memset(arr, 0, sizeof(arr));
	}
	
	
	return 0;
}