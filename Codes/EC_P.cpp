/*https://www.spoj.com/problems/EC_P/*/



#include<bits/stdc++.h>
using namespace std;
     
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long int
#define pb push_back
#define endl "\n"
#define ff first
#define ss second
#define N 1000009
#define mod 1000000007
#define med 998244353
#define debug cout<<"There There\n";
#define debug1(x) cout<<"\nValue is "<<x<<endl
#define debug2(x,y) cout<<"\nValue is "<<x<<" "<<y<<endl
#define debug3(x,y,z) cout<<"\nValue is "<<x<<" "<<y<<" "<<z<<endl  
#define pr pair<int,int>
#define mx INT_MAX
#define lmx LONG_MAX
#define err return 0
#define cn continue
#define bre break

int n,m;
int test;
vector<int> v[N];
int id=-1;
int dis[N];
int low[N];
bool visited[N];
vector<int> spe[N];

void dfs(int a,int b)
{
	visited[a]=1;
	id++;
	dis[a] = id;
	low[a] = id;
	for(auto i:v[a])
	{
		if(visited[i]==0)
		{
			spe[a].pb(i);
			dfs(i,a);
			low[a] = min(low[a],low[i]);
		}
		else if(i!=b)
		{
			low[a] = min(low[a],dis[i]);
		}
	}
}

int32_t main()
{
	//IOS;
	cin>>test;
	for(int te=1;te<=test;te++)
	{
		id =-1;
		cout<<"Caso #"<<te<<endl;
		cin>>n>>m;
		memset(visited,0,sizeof(visited));
		int d,t;
		for(int i=0;i<n;i++)
		{
			v[i].clear();
			spe[i].clear();
		}	
		for(int i=0;i<m;i++)
		{
			cin>>d>>t;
			d--;
			t--;
			v[d].pb(t);
			v[t].pb(d);
		}
		//debug;
		for(int i=0;i<n;i++)
		{
			if(visited[i]==0)
			{
				//cout<<i<<endl;
				dfs(i,-1);
			}
			//cout<<low[i]<<" "<<dis[i]<<endl;
		}

		//debug;
		vector<pr> p;
		for(int i=0;i<n;i++)
		{
			for(auto j:spe[i])
			{
				if(dis[i]<low[j])
				{
					if(i<j)
						p.pb({i,j});
					else
					{
						p.pb({j,i});
					}
					
				}
			}
		}
		if(p.size()==0)
		{
			cout<<"Sin bloqueos"<<endl;
			continue;
		}
		sort(p.begin(),p.end());
		cout<<p.size()<<endl;
		for(int i=0;i<p.size();i++)
		{
			cout<<p[i].ff+1<<" "<<p[i].ss+1<<endl;
		}
	}
}	
