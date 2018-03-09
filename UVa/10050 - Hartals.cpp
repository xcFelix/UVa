#include <iostream>
#include <set>
using namespace std;

int main()
{
	//freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
	//freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);

	
	int k;
	cin>>k;
	while(k--)
	{
		int n, p;
		cin>>n>>p;
		
		set<int> st;
		for(int i = 0; i<p; ++i)
		{
			int t;
			cin>>t;
			int _t = t;
			while(t<=n)
			{
				if(t%7!=6 && t%7!=0)
				{
					st.insert(t);
				}
				t+=_t;
			}
		}
		
		cout<<st.size()<<endl;
	}
	
	
	return 0;
}