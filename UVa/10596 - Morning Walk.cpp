#include <iostream>
#include <cstring>
using namespace std;

const int N = 209;

int p[N];
int d[N];

int find(int x)
{
	if(x==p[x]) return x;
	return p[x] = find(p[x]);
}

void unite(int a, int b)
{
	int x = find(a);
	int y = find(b);
	
	if(x==y) return;
	p[x] = y;
}

int n, r;

bool con()
{
	int sum = 0;
	for(int i = 0; i<n; ++i)
	{
		if(d[i] && p[i]==i) ++sum; //孤立的点不算！！！！ 
	}
	
	return sum==1;
}

bool euler_c()
{
	for(int i = 0; i<n; ++i)
	{
		if(d[i]&1) return false;
	}
	
	return true;
}

int main()
{
//	freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
//	freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	
	while(cin>>n>>r)
	{
		for(int i = 0; i<n; ++i) p[i] = i;
		memset(d, 0, sizeof(d));
		
		for(int i = 0; i<r; ++i)
		{
			int a, b;
			cin>>a>>b;
			
			unite(a, b);
			d[a]++;
			d[b]++;
		}
		
		if(con() && euler_c()) cout<<"Possible"<<endl;
		else cout<<"Not Possible"<<endl;
	}
	
	return 0;
}