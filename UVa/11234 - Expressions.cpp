#include <iostream>
#include <stack>
#include <queue>
#include <cctype>
using namespace std;

struct T{
	char a;
	T *l, *r;
	
	T(const char _a = ' ', T *_l = 0, T *_r = 0)
	: a(_a), l(_l), r(_r) {}
};

int main()
{
	//freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
	//freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);

	
	int n;
	cin>>n;
	while(n--)
	{
		stack<T *> S;
		string s;
		cin>>s;
		
		for(int i = 0; i<s.size(); ++i)
		{
			if(islower(s[i]))
			{
				S.push(new T(s[i]));
			}
			else
			{
				T *r = S.top(); S.pop();
				T *l = S.top(); S.pop();
				S.push(new T(s[i], l, r));
			}
		}
		
		s.clear();
		queue<T *> Q;
		Q.push(S.top());
		while(Q.size())
		{
			T *cur = Q.front(); Q.pop();
			if(cur->l) Q.push(cur->l);
			if(cur->r) Q.push(cur->r);
			
			s+=cur->a;
		}
		
		for(int i = s.size()-1; i>=0; --i) cout<<s[i];
		cout<<endl;
	}
	
	
	return 0;
}