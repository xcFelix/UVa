#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
	//freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
	//freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);

	
	int n;
	cin>>n;
	vector< vector<int> > v;
	map<int, int> mp;
	for(int i = 0; i<n; ++i)
	{
		v.push_back(vector<int>());
		v[i].push_back(i);
		mp[i] = i;
	}
	
	string s1, s2;
	int a, b;
	while(cin>>s1 && s1!="quit")
	{
		cin>>a>>s2>>b;
		if(s1=="move" && s2=="onto")
		{
			int src = mp[a];
			int des = mp[b];
			
			if(src==des) continue;
			
			while(v[src].back()!=a)
			{
				int t = v[src].back();
				v[src].pop_back();
				v[t].push_back(t);
				mp[t] = t;
			}
			
			while(v[des].back()!=b)
			{
				int t = v[des].back();
				v[des].pop_back();
				v[t].push_back(t);
				mp[t] = t;
			}
			
			v[src].pop_back();
			v[des].push_back(a);
			mp[a] = mp[b];
		}
		else if(s1=="move" && s2=="over")
		{
			int src = mp[a];
			int des = mp[b];
			
			if(src==des) continue;
			
			while(v[src].back()!=a)
			{
				int t = v[src].back();
				v[src].pop_back();
				v[t].push_back(t);
				mp[t] = t;
			}
			
			v[src].pop_back();
			v[des].push_back(a);
			mp[a] = mp[b];
		}
		else if(s1=="pile" && s2=="onto")
		{
			int src = mp[a];
			int des = mp[b];
			
			if(src==des) continue;
			
			while(v[des].back()!=b)
			{
				int t = v[des].back();
				v[des].pop_back();
				v[t].push_back(t);
				mp[t] = t;
			}
			
			int i = 0;
			while(v[src][i]!=a) ++i;
			for(; i<v[src].size(); ++i)
			{
				v[des].push_back(v[src][i]);
				mp[v[src][i]] = mp[b];
			}
			
			while(v[src].back()!=a) v[src].pop_back();
			v[src].pop_back();
		}
		else if(s1=="pile" && s2=="over")
		{
			int src = mp[a];
			int des = mp[b];
			
			if(src==des) continue;
			
			int i = 0;
			while(v[src][i]!=a) ++i;
			for(; i<v[src].size(); ++i)
			{
				v[des].push_back(v[src][i]);
				mp[v[src][i]] = mp[b];
			}
			
			while(v[src].back()!=a) v[src].pop_back();
			v[src].pop_back();
		}
	}
	
	for(int i = 0; i<n; ++i)
	{
		cout<<i<<':';
		if(v[i].size())
		{
			for(int j = 0; j<v[i].size(); ++j)
			{
				cout<<' '<<v[i][j];
			}
		}
		
		cout<<endl;
	}
	
	
	return 0;
}