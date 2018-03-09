#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;

struct T{
	char a, b;
	T(const string& s = "")
	: a(s[0]), b(s[1]) {}
	
	bool operator==(const T& t)
	{
		return (a==t.a || b==t.b);
	}
};

int main()
{
	//freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
	//freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);

	
	while(cin.peek()!='#')
	{
		list< vector<T> > lst;
		for(int i = 0; i<52; ++i)
		{
			lst.push_back(vector<T>());
			string s;
			cin>>s;
			lst.back().push_back(T(s));
		}
		cin.get();
		
		bool move = true;
		while(move)
		{
			move = false;
			list< vector<T> >::iterator it1, _it1, it2, it3;
			if(lst.size()==1) break;
			it1 = lst.begin();
			_it1 = it1;
			it2 = ++_it1;
			for(int i = 1; i<=2 && i<lst.size(); ++i)
			{	
				if(it2->back()==it1->back())
				{
					move = true;
					it1->push_back(it2->back());
					it2->pop_back();
					if(it2->empty()) lst.erase(it2);
					break;
				}
				
				++it1;
				++it2;
			}
			
			if(move || lst.size()<=3) continue;
			it1 = lst.begin();
			_it1 = it1;
			it2 = ++(++_it1);
			it3 = ++_it1;
			
			for(int i = 3; i<lst.size(); ++i)
			{
				if(it1->back()==it3->back())
				{
					move = true;
					it1->push_back(it3->back());
					it3->pop_back();
					if(it3->empty()) lst.erase(it3);
					break;
				}
				else if(it2->back()==it3->back())
				{
					move = true;
					it2->push_back(it3->back());
					it3->pop_back();
					if(it3->empty()) lst.erase(it3);
					break;
				}
				
				++it1;
				++it2;
				++it3;
			}
		}
		
		cout<<lst.size();
		if(lst.size()==1) cout<<" pile remaining:";
		else cout<<" piles remaining:";
		list< vector<T> >::iterator it;
		for(it = lst.begin(); it!=lst.end(); ++it)
		{
			cout<<' '<<it->size();
		}
		cout<<endl;
	}
	
	
	return 0;
}