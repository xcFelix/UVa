#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

int main()
{
	//freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
	//freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	
	int sum_case = 0;
	int K, E;
	while(cin>>K>>E)
	{
		cout<<"Excuse Set #"<<++sum_case<<endl;
		
		vector<string> v1, v2, v_temp;
		vector<int> v3;
		for(int i = 0; i<K; ++i)
		{
			string s;
			cin>>s;
			v1.push_back(s);
		}
		cin.get();
		
		for(int i = 0; i<E; ++i)
		{
			string s;
			getline(cin, s);
			v_temp.push_back(s);
			for(int i = 0; i<s.size(); ++i) s[i] = tolower(s[i]);
			s.push_back('#');
			v2.push_back(s);
		}
		
		int max_sum = -1;
		int sum;
		for(int i = 0; i<v2.size(); ++i)
		{
			sum = 0;
			for(int j = 0; j<v1.size(); ++j)
			{
				int index = 0;
				while(true)
				{
					index = v2[i].find(v1[j], index);
					if(index!=string::npos)
					{
						if(!isalpha(v2[i][index-1]) && !isalpha(v2[i][index+v1[j].size()])) ++sum;
						++index;
					}
					else break;
				}
			}
			
			max_sum = max(max_sum, sum);
			v3.push_back(sum);
		}
		
		for(int i = 0; i<v3.size(); ++i)
		{
			if(v3[i]==max_sum) cout<<v_temp[i]<<endl;
		}
		cout<<endl;
	}
	
	
	return 0;
}