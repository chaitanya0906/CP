//Miss ME??
#include <bits/stdc++.h>
using namespace std;

#define N 2000000

int t[N],n;
int a[N];
int lef,rig;

void build(int node=1,int l=0,int r=n-1)
{
	if(l==r)
	{
		t[node]=a[l];
		return ;
	}
	int mid=(l+r)/2;
	build(2*node,l,mid);
	build(2*node+1,mid+1,r);
	t[node]=t[2*node]+t[2*node+1];
}

int query(int node=1,int s=0,int e=n-1,int l=lef,int r=rig)
{
	if(s>r||e<l)
		return 0;
	if(s>=l&&r>=e)
	{
		return t[node];
	}
	int mid=(s+e)/2;
	return query(node*2,s,mid,l,r)+query(node*2+1,mid+1,e,l,r);
}

int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	build();
	cin>>lef>>rig;
	cout<<query()<<endl;
}
