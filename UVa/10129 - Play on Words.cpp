#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
using namespace std;

int ind[29];
int outd[29];

int par[29];
bool vis[29];

void init()
{
	for(int i = 0; i<26; ++i) par[i] = i;
}

int find(int a)
{
	if(par[a]==a) return a;
	return par[a] = find(par[a]);
}

void unite(int a, int b)
{
	int x = find(a);
	int y = find(b);
	
	if(x==y) return;
	par[x] = y;
}

bool con()
{
	int sum = 0;
	for(int i = 0; i<26; ++i)
	{
		if(vis[i] && par[i]==i) ++sum;
	}
	
	return sum==1;
}

bool valid()
{	
	bool in = false;
	bool out = false;
	
	for(int i = 0; i<26; ++i)
	{
		if(ind[i]==outd[i]) continue;
		if(abs(ind[i]-outd[i])!=1) return false;
		if(ind[i]-outd[i]==1)
		{
			if(in) return false;
			in = true;
		}
		else if(ind[i]-outd[i]==-1)
		{
			if(out) return false;
			out = true;
		}
	}
	
	if(in && out || !in && !out) return true;
	return false;
}

int main()
{
//	freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
//	freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	
	int n;
	cin>>n;
	while(n--)
	{
		memset(ind, 0, sizeof(ind));
		memset(outd, 0, sizeof(outd));
		memset(vis, 0, sizeof(vis));
		init();
		
		int m;
		cin>>m;
		
		for(int i = 0; i<m; ++i)
		{
			string s;
			cin>>s;
			
			int a = s[0]-'a';
			int b = s[s.size()-1]-'a';
			
			vis[a] = vis[b] = true;
			
			unite(a, b);
			ind[b]++;
			outd[a]++;
		}
		
		if(con() && valid()) cout<<"Ordering is possible."<<endl;
		else cout<<"The door cannot be opened."<<endl;
	}
	
	
	return 0;
}