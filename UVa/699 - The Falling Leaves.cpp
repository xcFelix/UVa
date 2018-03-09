#include <iostream>
#include <map>
using namespace std;

struct T{
	int data;
	T *l, *r;
	
	T(const int& _data = 0, T *_l = 0, T *_r = 0)
	: data(_data), l(_l), r(_r) {}
};

T* Tree(int n)
{
	if(n==-1) return NULL;
	
	T* root = new T(n);
	
	cin>>n;
	root->l = Tree(n);
	cin>>n;
	root->r = Tree(n);
	
	return root;
}

void dfs(T* root, int n, map<int, int>& mp)
{
	if(root==NULL) return;
	
	mp[n]+=root->data;
	dfs(root->l, n-1, mp);
	dfs(root->r, n+1, mp);
}

int main()
{
	//freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
	//freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	
	int sum_case = 0;
	int n;
	while(cin>>n)
	{
		T* root = Tree(n);
		
		map<int, int> mp;
		dfs(root, 0, mp);
		
		if(root==NULL) break;
		
		cout<<"Case "<<++sum_case<<':'<<endl;
		cout<<mp.begin()->second;
		for(map<int, int>::iterator it = ++mp.begin(); it!=mp.end(); ++it) cout<<' '<<it->second;
		cout<<endl<<endl;
	}
	
	
	return 0;
}