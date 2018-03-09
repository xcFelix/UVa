#include <iostream>
#include <cmath>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

struct T{
	int x, y, z;
	
	T(const int& _x, const int& _y, const int& _z)
	:x(_x), y(_y), z(_z) {}
	
	int cal(const T& t)
	{
		return sqrt(pow(x-t.x, 2) + pow(y-t.y, 2) + pow(z-t.z, 2));
	}
};

int arr[19];

int main()
{
	//freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
	//freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	
	vector<T> v;
	int a, b, c;
	while(cin>>a>>b>>c && !(a==0 && b==0 && c==0))
	{
		v.push_back(T(a, b, c));
	}
	
	for(int i = 0; i<v.size(); ++i)
	{
		int min_dis = 10;
		for(int j = 0; j<v.size(); ++j)
		{
			if(j==i) continue;
			int dis = v[i].cal(v[j]);
			if(dis<10) min_dis=min(min_dis, dis);
		}
		++arr[min_dis];
	}
	
	for(int i = 0; i<10; ++i)
	{
		printf("%4d", arr[i]);
	}
	cout<<endl;
	
	
	return 0;
}