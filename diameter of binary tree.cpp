#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll maxi=0;
class tree
{
	public:
	ll data;
	tree * left;
	tree * right;
};
tree * push(ll da)
{
	tree * nn=new tree();
	nn->data=da;
	nn->left=NULL;
	nn->right=NULL;
	return nn;
}
ll dia(tree * root)
{
	ll l=0,r=0;
	if(root==NULL)
	return 0;
	if(root->left!=NULL)
	 l=dia(root->left);
	if(root->right!=NULL)
	 r=dia(root->right);
	if((l+r)>maxi)
	maxi=l+r;
	return max(l,r)+1;
}
void inorder(tree * root)
{
	if(root==NULL)
	return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);	
}
int main()
{
	ll n,c;
	cin>>n>>c;
	tree * root=push(c);
	n=n-1;
	while(n--)
	{
		string s;
		cin>>s;
		ll j=0;
		tree * po=root;
		while(s[j] && po!=NULL)
		{
			if(s[j]=='L')
			{
			    if(po->left==NULL)
		           {
			        po->left=push(0);
		           }
		           po=po->left;
			}
			else
			{
				    if(po->right==NULL)
		           {
			        po->right=push(0);
		           }	
		           po=po->right;
			}
			j++;
		}
		ll k;
		cin>>k;
		po->data=k;
	}
	inorder(root);
dia(root);
cout<<maxi+1<<endl;
}
