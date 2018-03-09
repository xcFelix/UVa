#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 109;
char top[N];
char bot[N];
char arr[N*3];

int main()
{
//	freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
//	freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	
	while(gets(bot) && gets(top))
	{
		memset(arr, 0, sizeof(arr));
		
		int len1 = strlen(bot);
		int len2 = strlen(top);
		
		strcpy(arr+len2, bot);
		
		int min_n = 1<<30;
		int len = len1+len2;
		for(int i = 0; i<len; ++i)
		{
			bool ok = true;
			for(int j = 0; j<len2; ++j)
			{
				if(top[j]=='2' && arr[i+j]=='2')
				{
					ok = false;
					break;
				}
			}
			
			if(ok)
			{
				int l = min(i, len1);
				int r = max(len, i+len1);
				
				min_n = min(min_n, r-l);
			}
		}
		
		cout<<min_n<<endl;
	}
	
	
	return 0;
}