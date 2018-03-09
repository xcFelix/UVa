#include iostream
#include cstdio
using namespace std;

bool used[19];

int main()
{
	//freopen(CUsersAdministratorDesktopstdout.txt, w, stdout);
	//freopen(CUsersAdministratorDesktopstdin.txt, r, stdin);

	
	int n, k, m;
	while(cinnkm && n)
	{
		for(int i = 1; i=n; ++i) used[i] = false;
		
		int r = n;
		int l = 1;
		int sum = 0;
		while(sum!=n)
		{
			for(int i = 1; i=k; ++i)
			{
				if(++r==n+1) r= 1;
				while(used[r]==true)
				{
					if(++r==n+1) r = 1;
				}
			}
			
			for(int j = 1; j=m; ++j)
			{
				if(--l==0) l = n;
				while(used[l]==true)
				{
					if(--l==0) l = n;
				}
			}
			
			printf(%3d, r);
			used[r] = true;
			++sum;
			if(l!=r)
			{
				printf(%3d, l);
				used[l] = true;
				++sum;
			}
			
			if(sum!=n) cout',';
		}
		
		coutendl;
	}
	
	
	return 0;
}