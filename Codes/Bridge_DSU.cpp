/*
  https://codeforces.com/contest/1000/problem/E HI
*/
#include<bits/stdc++.h>
using namespace std;
     
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define int long long int
#define pb push_back
#define endl "\n"
#define ff first
#define ss second
#define N 300009
#define NN 3000009
#define M 509
#define mod 1000000007
#define debug cout<<"There There\n";
#define debug1(x) cout<<"\nValue is "<<x<<endl
#define debug2(x,y) cout<<"\nValue is "<<x<<" "<<y<<endl
#define debug3(x,y,z) cout<<"\nValue is "<<x<<" "<<y<<" "<<z<<endl  
#define pq priority_queue<int>
#define mpq priority_queue<int,vector<int>,greater<int>>
#define pr pair<int,int>
#define mx INT_MAX
#define lmx LLONG_MAX
#define err return 0          
#define all(a) a.begin(),a.end()

int n,m;
int x,y;
int T=1;
bool visited[N];
int tin[N];
int low[N];
vector<pr> wo;
int par[N];
int ranki[N];
vector<int> v[N];
vector<int> tree[N];

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

void dfs(int a,int p)
{
     visited[a] = 1;
     tin[a] = T++;
     low[a] = T;
     for(auto to:v[a])
     {
          if(to==p)
               continue;
          if(visited[to])
          {
               low[a] = min(low[a],tin[to]);
          }
          else
          {
               dfs(to,a);
               low[a] = min(low[a],low[to]);
               if(low[to]>tin[a])
               {
                    wo.pb({a,to});
               }
               else
               {
                    merge(a,to);
               }
          }
     }
}

pair<int,int> bfs(int st)
{
     memset(low,0,sizeof(low));
     //int last = st;
     low[st] = 0;
     queue<int> q;
     q.push(st);
     int last = st;
     while(!q.empty())
     {
          last = q.front();
          q.pop();
          for(auto i:tree[last])
          {
               if(i==st||low[i]!=0)
                    continue;
               low[i] = low[last]+1;
               q.push(i);
          }
     }
     return {last,low[last]};
}

int32_t main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);
     memset(visited,0,sizeof(visited));
     memset(tin,0,sizeof(tin));
     memset(low,0,sizeof(low));
     init();
     cin>>n>>m;
     for(int i=0;i<m;i++)
     {
          cin>>x>>y;
          v[x].pb(y);
          v[y].pb(x);
     }
     dfs(1,0);
     for(int i=1;i<=n;i++)
     {
          int temp = find(i);
     }    
     for(auto i:wo)
     {
          int a = i.ff;
          int b = i.ss;
          a = find(a);
          b = find(b);
          tree[a].pb(b);
          tree[b].pb(a);
     }
     int start = find(1);
     pr p1  = bfs(start);
     pr p2 = bfs(p1.ff);
     cout<<p2.ss<<endl;
}
