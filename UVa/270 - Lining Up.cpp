#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <sstream>
using namespace std;

const double eps = 1e-9;

struct P{
	int x;
	int y;
	
	P(const int& _x, const int& _y)
	:x(_x), y(_y) {}
};

int main()
{
//	freopen("stdout.txt", "w", stdout);
//	freopen("stdin.txt", "r", stdin);
	
	
	int n;
	cin>>n;
	cin.get();
	cin.get();
	while(n--)
	{
		vector<P> v1;
		string s;
		while(getline(cin, s))
		{
			if(!s.size()) break;
			
			int x, y;
			stringstream ss(s);
			ss>>x>>y;
			v1.push_back(P(x, y));
		}
		
		int _max = 0;
		for(int i = 0; i<v1.size(); ++i)
		{
			vector<double> v2;
			for(int j = 0; j<v1.size(); ++j)
			{
				if(j==i) continue;
				double d = (double)(v1[i].y-v1[j].y) / (v1[i].x-v1[j].x);
				v2.push_back(d);
			}
			
			sort(v2.begin(), v2.end());
			
			for(int j = 0; j<v2.size(); )
			{
				for(int k = j+1; k<=v2.size(); ++k)
				{	
					if(k==v2.size() || fabs(v2[j]-v2[k])>eps)
					{
						_max = max(_max, k-j);
						j = k;
						break;
					}
				}
			}
		}
		
		cout<<_max+1<<endl;
		if(n) cout<<endl;
	}
	
	
	return 0;
}