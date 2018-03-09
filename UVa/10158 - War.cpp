#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

const int N = 10009;
int par[2*N];

void init(int n)
{
	for(int i = 0; i<2*n; ++i) par[i] = i;
}

int find(int x)
{
	if(par[x]==x) return x;
	return par[x] = find(par[x]);
}

void unite(int a, int b)
{
	int x = find(a);
	int y = find(b);
	
	if(x!=y) par[x] = y;
}

bool same(int a, int b)
{
	return find(a)==find(b);
}

int main()
{
//	freopen("stdout.txt", "w", stdout);
//	freopen("stdin.txt", "r", stdin);
	
	
	int n;
	while(cin>>n)
	{
		init(n);
		
		int c, a, b;
		while(cin>>c>>a>>b && c)
		{
			switch(c)
				{
				case 1:
					{
						if(same(a, b+n)) cout<<-1<<endl;
						else
						{
							unite(a, b);
							unite(a+n, b+n);
						}
						break;
					}
				case 2:
					{
						if(same(a, b)) cout<<-1<<endl;
						else
						{
							unite(a, b+n);
							unite(a+n, b);
						}
						break;
					}
				case 3:
					{
						if(same(a, b)) cout<<1<<endl;
						else cout<<0<<endl;
						break;
					}
				case 4:
					{
						if(same(a, b+n)) cout<<1<<endl;
						else cout<<0<<endl;
						break;
					}
				}
		}
	}
	
	
	return 0;
}