/*
  https://codeforces.com/contest/25/problem/D
*/
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);cout.precision(10);cout<<fixed;
#define int long long int
#define pb push_back
#define endl "\n"
#define ff first
#define ss second
#define N 1009
#define M 59
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

int n;
int par[N];
pr p[N];
int ranki[N];
vector<int> v[N];

void init()
{
	for(int i=0;i<N;i++)
	{
		par[i]=i;
	}
}

int find(int x)
{
	if(par[x]!=x)
	{
		par[x] = find(par[x]);
		return par[x];
	}
	return x;
}

bool merge(int x,int y)
{
	int a = find(x);
	int b = find(y);
	if(a==b)
	{
		return 1;
	}
	if(ranki[a]==ranki[b])
	{
		ranki[a]++;
	}
	else if(ranki[a]<ranki[b])
	{
		swap(a,b);
	}
	par[b] = a;
	return 0;
}


int32_t main()
{
	IOS;
	memset(ranki,0,sizeof(ranki));
	init();
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		int x,y;
		cin>>x>>y;
		x--,y--;
		v[x].pb(y);
	}
	vector<pr> del;
	for(int i=0;i<n;i++)
	{
		for(auto j:v[i])
		{
			if(merge(i,j))
			{
				del.pb({i,j});
			}
		}	
	}
	cout<<del.size()<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(!merge(i,j))
			{
				pr p = del.front();
				cout<<p.ff+1<<" "<<p.ss+1<<" "<<i+1<<" "<<j+1<<endl;
				del.erase(del.begin());
			}
		}
	}
	err;
}	
