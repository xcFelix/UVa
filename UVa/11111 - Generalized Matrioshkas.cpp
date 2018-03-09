#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

struct T{
	int a;
	int sum;
	
	T(const int& _a, const int& _sum = 0)
	:a(_a), sum(_sum) {}
};

bool valid(stringstream& ss)
{
	vector<T> v;
	int a;
	while(ss>>a)
	{
		if(a<0) v.push_back(T(-a));
		else
		{
			if(v.empty()) return false;
			if(v.back().a!=a) return false;
			
			T t =v.back(); v.pop_back();
			if(v.empty())
			{
				if(ss>>a) return false;
				return true;
			}
			
			v.back().sum+=t.a;
			if(v.back().a<=v.back().sum) return false;
		}
	}
	
	return v.empty();
}

int main()
{
	//freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
	//freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);

	
	string s;
	while(getline(cin, s))
	{
		stringstream ss(s);
		if(valid(ss)) cout<<":-) Matrioshka!"<<endl;
		else cout<<":-( Try again."<<endl;
	}
	
	
	return 0;
}