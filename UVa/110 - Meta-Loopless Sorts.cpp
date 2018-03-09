#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int a;

void space(int n)
{
	for(int i = 0; i<n; ++i) cout<<"  ";
}

void dfs(string& s)
{
	int d = s.size();
	if(d==a)
	{
		space(d);
		cout<<"writeln(";
		cout<<s[0];
		for(int i = 1; i<a; ++i) cout<<','<<s[i];
		cout<<')'<<endl;
		
		return;
	}
	
	for(int i = d; i>=0; --i)
	{
		space(d);
		if(i!=d) cout<<"else ";
		
		if(i)
		{
			printf("if %c < %c then\n", s[i-1], 'a'+d);
			s.insert(i, 1, 'a'+d);
			dfs(s);
			s.erase(i, 1);
		}
		else
		{
			cout<<endl;
			s.insert(0, 1, 'a'+d);
			dfs(s);
			s.erase(0, 1);
		}
	}
}

int main()
{
//	freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
//	freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	
	int t;
	cin>>t;
	while(t--)
	{
		cin>>a;
		
		cout<<"program sort(input,output);"<<endl;
		cout<<"var"<<endl;
		cout<<'a';
		for(int i = 1; i<a; ++i) cout<<','<<(char)('a'+i);
		cout<<" : integer;"<<endl;
		cout<<"begin"<<endl;
		cout<<"  readln(a";
		for(int i = 1; i<a; ++i) cout<<','<<(char)('a'+i);
		cout<<");"<<endl;;
		
		string s("a");
		dfs(s);
		cout<<"end."<<endl;
		
		if(t) cout<<endl;
	}
	
	
	return 0;
}