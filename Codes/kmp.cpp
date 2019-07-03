#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int unsigned long long int
#define pb push_back
#define endl "\n"
#define ff first
#define ss second
#define N 100009
#define mod 1000000007
#define med 998244353
#define debug cout<<"There There\n";
#define debug1(x) cout<<"\nValue is "<<x<<endl
#define debug2(x,y) cout<<"\nValue is "<<x<<" "<<y<<endl
#define debug3(x,y,z) cout<<"\nValue is "<<x<<" "<<y<<" "<<z<<endl
#define pr pair<int,int>
#define err return 0	
#define mx INT_MAX
#define lmx LLONG_MAX
#define cn continue
#define bre break

int n,m;
string s,t;
int pi[N];
int ans=0;

void pre()
{
	pi[1]=0;
	memset(pi,0,sizeof(pi));
	int k=0;
	for(int i=2;i<=n;i++)
	{
		while(k>0&&s[k]!=s[i-1])
		{
			k = pi[k];
		}
		if(s[k]==s[i-1])
		{
			k=k+1;
		}	
		pi[i]=k;
	}
}

void kmp()
{
	int q=0;
	for(int i=0;i<m;i++)
	{
		while(q>0&&t[i]!=s[q])
		{
			q=pi[q];
		}
		if(s[q]==t[i])
			q=q+1;
		if(q==n)
		{
			ans++;
			//debug1(i);
			q=pi[q];
		}
	}
}

int32_t main()
{
	IOS;
	cin>>s>>t;
	n=s.length();
	m=t.length();
	pre();
	/*for(int i=1;i<=n;i++)
	{
		cout<<pi[i]<<" ";
	}*/
	kmp();
	cout<<ans<<endl;
	err;
}	
