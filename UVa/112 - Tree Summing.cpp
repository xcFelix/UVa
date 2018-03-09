#include <iostream>
using namespace std;

struct T{
	int data;
	T *l, *r;
	
	T(const int& _data=0, T* _l=0, T* _r=0)
	: data(_data), l(_l), r(_r) {}
};

T* Tree()
{
	char ch;
	cin>>ch;
	int n;
	if(cin>>n)
	{
		T* root = new T(n);
		root->l = Tree();
		root->r = Tree();
		
		cin>>ch;
		return root;
	}
	else
	{
		cin.clear();
		cin>>ch;
		return NULL;
	}
}

bool dfs(T* root, int sum, const int& n)
{	
	sum+=root->data;
	if(root->l==NULL && root->r==NULL)
	{
		if(sum==n) return true;
	}
	else
	{
		if(root->l) if(dfs(root->l, sum, n)) return true;
		if(root->r) if(dfs(root->r, sum, n)) return true;
	}
	
	return false;
}

int main()
{
//	freopen("C:\\Users\\Administrator\\Desktop\\stdout.txt", "w", stdout);
//	freopen("C:\\Users\\Administrator\\Desktop\\stdin.txt", "r", stdin);
	
	
	int n;
	while(cin>>n)
	{
		T* root = Tree();
		
		if(root==NULL) cout<<"no"<<endl;
		else if(dfs(root, 0, n)) cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
	
	
	return 0;
}