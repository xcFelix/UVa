#include <iostream>
#include <cstring>
using namespace std;

int DNA[19];
int dish[49];
char conversion[] = { ' ', '.', 'x', 'W' };

int main()
{
	//freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
	//freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);

	
	int n;
	cin>>n;
	while(n--)
	{
		cout<<"                   .                    "<<endl;
		
		for(int i = 0; i<10; ++i) cin>>DNA[i];
		
		memset(dish, 0, sizeof(dish));
		dish[20] = 1;
		
		for(int i = 1; i<50; ++i)
		{
			int temp = 0;
			for(int j = 1; j<=40; ++j)
			{
				int t = dish[j];
				dish[j] = DNA[temp+dish[j]+dish[j+1]];
				temp = t;
				
				cout<<conversion[dish[j]-0];
			}
			
			cout<<endl;
		}
		
		if(n) cout<<endl;
	}
	
	
	return 0;
}