#include <iostream>
#include <deque>
#include <queue>
#include <vector>
using namespace std;

const int MAX_N = 1000000;
int par[MAX_N];
int rank[MAX_N];

int find(int x)
{
	if(par[x]==x) return x;
	return par[x] = find(par[x]);
}

bool same(int x, int y)
{
	return find(x) == find(y);
}

void unite(int x, int y)
{
	x = find(x);
	y = find(y);
	if(x==y) return;
	
	if(rank[x]<rank[y]) par[x] = y;
	else
	{
		par[y] = x;
		if(rank[x]==rank[y]) ++rank[x];
	}
}

int main()
{
	//freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
	//freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);

	
	int sum_case = 0;
	int n;
	while(cin>>n && n)
	{
		cout<<"Scenario #"<<++sum_case<<endl;
		
		for(int i = 0; i<n; ++i)
		{
			int m;
			cin>>m;
			vector<int> v;
			for(int j = 0; j<m; ++j)
			{
				int t;
				cin>>t;
				v.push_back(t);
			}
			
			par[v[0]] = v[0];
			for(int j = 1; j<v.size(); ++j)
			{
				par[v[j]] = v[j];
				unite(v[j-1], v[j]);
			}
		}
		
		deque< queue<int> > dq;
		string s;
		while(cin>>s && s!="STOP")
		{
			if(s=="ENQUEUE")
			{
				int t;
				cin>>t;
				
				bool has = false;
				for(int i = 0; i<dq.size(); ++i)
				{
					if(same(dq[i].front(), t))
					{
						dq[i].push(t);
						has = true;
						break;
					}
				}
				
				if(!has)
				{
					dq.push_front(queue<int>());
					dq[0].push(t);
				}
			}
			else if(s=="DEQUEUE")
			{
				cout<<dq.back().front()<<endl;
				dq.back().pop();
				if(dq.back().size()==0) dq.pop_back();
			}
		}
		
		cout<<endl;
	}
	
	
	return 0;
}