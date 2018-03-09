#include <iostream>
#include <set>
using namespace std;

int main()
{
	//freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
	//freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);


	int sum_case = 0;
	int z, i, m, l;
	while(cin>>z>>i>>m>>l && z)
	{
		l = (z*l+i)%m;
		set<int> st;
		st.insert(l);
		while(true)
		{
			l = (z*l+i)%m;
			if(st.count(l)) break;
			st.insert(l);
		}
		
		cout<<"Case "<<++sum_case<<": "<<st.size()<<endl;
	}
	
	
	return 0;
}