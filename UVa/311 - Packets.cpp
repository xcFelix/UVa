#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
//	freopen("stdout.txt", "w", stdout);
//	freopen("stdin.txt", "r", stdin);
	
	
	int s1, s2, s3, s4, s5, s6;
	while(cin>>s1>>s2>>s3>>s4>>s5>>s6 && s1+s2+s3+s4+s5+s6)
	{
		int b1 = 0;
		int b2 = 0;
		int sum = s6;
		
		sum+=s5;
		b1+=s5*11;
		
		sum+=s4;
		b2+=s4*5;
		
		sum+=s3/4;
		int a = s3%4;
		if(a)
		{
			sum++;
			a = 4-a;
			
			switch(a)
			{
				case 1:
					{
						b2++;
						b1+=5;
						break;
					}
				case 2:
					{
						b2+=3;
						b1+=6;
						break;
					}
				case 3:
					{
						b2+=5;
						b1+=7;
						break;
					}
			}
		}
		
		if(b2>=s2)
		{
			b2-=s2;
			b1+=b2*4;
		}
		else
		{
			s2-=b2;
			sum+=s2/9;
			int a = s2%9;
			if(a)
			{
				sum++;
				
				a = 9-a;
				b1+=a*4;
			}
		}
		
		if(b1>=s1) ;
		else
		{
			s1-=b1;
			sum+=s1/36;
			s1%=36;
			if(s1) sum++;
		}
		
		cout<<sum<<endl;
	}
	
	
	return 0;
}