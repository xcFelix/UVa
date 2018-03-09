#include <iostream>
#include <cmath>
#include <vector>
#include <set>
using namespace std;

const double eps = 1e-9;

struct V{
	char name;
	int x, y;
	
	V() {}
	V(char _name, int _x, int _y)
	: name(_name), x(_x), y(_y) {}
	
	bool operator==(const V& v) const
	{
		return name==v.name;
	}
};

struct T{
	V a, b, c;
	double area;
	
	T() {}
	T(const V& _a, const V& _b, const V& _c)
	: a(_a), b(_b), c(_c) {}
	
	T& cal_area()
	{
		area = fabs((a.x-b.x)*(a.y-c.y) - (a.x-c.x)*(a.y-b.y));
		return *this;
	}
	
	double cal_area(const V& a, const V& b, const V& c) const
	{
		return fabs((a.x-b.x)*(a.y-c.y) - (a.x-c.x)*(a.y-b.y));
	}
	
	bool is_in(const V& v) const
	{
		double area_1 = cal_area(a, b, v);
		double area_2 = cal_area(a, c, v);
		double area_3 = cal_area(b, c, v);
		double _area = area_1+area_2+area_3;
		
		return (fabs(area-_area)<eps);
	}
	
	bool has(const V& v) const
	{
		return (a==v || b==v || c==v);
	}
	
	bool operator<(const T& t) const
	{
		return area>t.area;
	}
};

int main()
{
	//freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
	//freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);

	
	int n;
	while(cin>>n && n)
	{
		vector<V> v;
		for(int i = 0; i<n; ++i)
		{
			char ch;
			int a, b;
			cin>>ch>>a>>b;
			v.push_back(V(ch, a, b));
		}
		
		multiset<T> st;
		for(int i = 0; i<v.size()-2; ++i)
		{
			for(int j = i+1; j<v.size()-1; ++j)
			{
				for(int k = j+1; k<v.size(); ++k)
				{
					st.insert(T(v[i], v[j], v[k]).cal_area());
				}
			}
		}
		
		set<T>::iterator it = st.begin();
		for(; it!=st.end(); ++it)
		{
			bool ok = true;
			for(int i = 0; i<v.size(); ++i)
			{
				if(!it->has(v[i]))
				{
					if(it->is_in(v[i]))
					{
						ok = false;
						break;
					}
				}
			}
			
			if(ok) break;
		}
		
		cout<<it->a.name<<it->b.name<<it->c.name<<endl;
	}
	
	
	return 0;
}