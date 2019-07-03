//Miss ME??
#include <bits/stdc++.h>
using namespace std;

#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long int
#define N 7000009
#define pb push_back

string s;
int q;
int l,r;
int n,see;

struct node
{
	int ans=0;
	int l=0;
	int r=0;
};

node t[N];

node merge(node a,node b)
{
	node temp;
	see=min(a.r,b.l);
	temp.ans=a.ans+b.ans+see;
	temp.r=a.r+b.r-see;
	temp.l=a.l+b.l-see;
	return temp;
}

void build(int node, int L, int R)
{
	if(L==R)
	{
		if(s[L]=='(')
		{
			t[node].r=1;
		}
		else
		{
			t[node].l=1;
		}
		return;
	}
	int M=(L+R)>>1;
	build(node+node,L,M);
	build(node+node+1,M+1,R);
	t[node]=merge(t[node+node],t[node+node+1]);
}

node query(int nodei,int L,int R,int i,int j)
{
	if(j<L || i>R)
	{
		struct node seti;
		return seti;
	}
	if(i<=L && R<=j)
	{
		return t[nodei];
	}
	int M=(L+R)>>1;
	struct node n1=query(nodei+nodei, L, M, i, j);
	struct node n2=query(nodei+nodei+1, M+1, R, i, j);
	struct node reqd;
	reqd=merge(n1,n2);
	return reqd;
}

signed main()
{	
	cin>>s;
	n=s.length();
	build(1,0,n-1);
	/*for(int i=1;i<32;i++)
	{
		cout<<t[i].ans<<" "<<t[i].l<<" "<<t[i].r<<endl;
	}*/
	cin>>q;
	while(q--)
	{
		cin>>l>>r;
		cout<<2*query(1,0,n-1,l-1,r-1).ans<<endl ;
	}
}		
