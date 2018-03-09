#include <iostream>
#include <cstring>
#include <cstdio>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 119;
char _arr[N];
char arr[N];

struct T{
	char c;
	int a;
	
	T(const char& _c, const int& _a)
	: c(_c), a(_a) {}
	
	bool operator<(const T& t) const
	{
		return c<t.c;
	}
};

int main()
{
//	freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
//	freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	
	while(gets(_arr))
	{	
		for(int i = 0, j = 0; _arr[i]; ++i)
		{
			if(_arr[i]!=' ')
			{
				arr[j++] = _arr[i];
				arr[j] = '\0';
			}
		}
		
		vector<T> v;
		int len = strlen(arr);
		
		int i;
		int sum = 0;
		if(!isalpha(arr[0]))
		{
			T t(arr[2], arr[2]-'a'+1);
			
			if(arr[0]=='+') ++t.a;
			else --t.a;
			
			v.push_back(t);
			sum+=t.a;
			i = 4;
		}
		else if(3<=len && arr[1]==arr[2])
		{
			T t(arr[0], arr[0]-'a'+1);
			
			sum+=t.a;
			if(arr[1]=='+') ++t.a;
			else --t.a;
			
			v.push_back(t);
			i = 4;
		}
		else
		{
			T t(arr[0], arr[0]-'a'+1);
			
			sum+=t.a;
			v.push_back(t);
			i = 2;
		}
		
		for(; i<len; )
		{
			int j = 0;
			while(!isalpha(arr[i])) ++i, ++j;
			
			if(j==2)
			{
				T t(arr[i], arr[i]-'a'+1);
				
				if(arr[i-1]=='+') ++t.a;
				else --t.a;
				
				v.push_back(t);
				
				if(arr[i-3]=='+') sum+=t.a;
				else sum-=t.a;
				
				i+=2;
			}
			else if(i+2<len && arr[i+1]==arr[i+2])
			{
				T t(arr[i], arr[i]-'a'+1);
				
				if(arr[i-1]=='+') sum+=t.a;
				else sum-=t.a;
				
				if(arr[i+1]=='+') ++t.a;
				else --t.a;
				
				v.push_back(t);
				i+=4;
			}
			else
			{
				T t(arr[i], arr[i]-'a'+1);
				
				if(arr[i-1]=='+') sum+=t.a;
				else sum-=t.a;
				
				v.push_back(t);
				i+=2;
			}
		}
		
		cout<<"Expression: "<<_arr<<endl;
		cout<<"    value = "<<sum<<endl;
		sort(v.begin(), v.end());
		for(int i = 0; i<v.size(); ++i)
		{
			cout<<"    "<<v[i].c<<" = "<<v[i].a<<endl;
		}
	}
	
	
	return 0;
}