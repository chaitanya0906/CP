/*
	https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/practice-problems/algorithm/help-ashu-1/

*/

#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long int
#define pb push_back
#define endl "\n"
#define ff first
#define ss second
#define N 300009
#define M 59
#define mod 1000000007
#define med 998244353
#define debug cout<<"There There\n";
#define debug1(x) cout<<"\nValue is "<<x<<endls
#define debug2(x,y) cout<<"\nValue is "<<x<<" "<<y<<endl
#define debug3(x,y,z) cout<<"\nValue is "<<x<<" "<<y<<" "<<z<<endl
#define pr pair<int,int>
#define err return 0	
#define mx INT_MAX
#define lmx LLONG_MAX`
#define cn continue
#define bre break

int n;
int t[4*N];
int a[N];
int q;
int x,y,z;

void build(int node,int s,int e)
{
     if(s==e)
     {
          t[node] = (a[s])%2;
          return;
     }
     int mid = (s+e)/2;
     build(2*node+1,s,mid);
     build(2*node+2,mid+1,e);
     t[node] = t[2*node+1]+t[2*node+2];
}

int query(int node,int s,int e,int l,int r)
{
     if(r<s||e<l)
     {
          return 0;
     }
     if(l<=s && r>=e)
     {
          return t[node];
     }
     int mid = (s+e)/2;
     return (query(2*node+1,s,mid,l,r)+query(2*node+2,mid+1,e,l,r));
}

void update(int node,int s,int e,int l,int r,int val)
{
     if(s>r||e<l)
     {
          return;
     }
     if(s==e)  
     {
          t[node]=val%2;
          a[s]=val%2;
          return;
     }
     int mid = (s+e)/2;
     update(2*node+1,s,mid,l,r,val);
     update(2*node+2,mid+1,e,l,r,val);
     t[node] = t[2*node+1]+t[2*node+2];
}

int32_t main()
{
     IOS;
     cin>>n;
     for(int i=0;i<n;i++)
     {
          cin>>a[i];
          a[i]=a[i]%2;
     }
     build(0,0,n-1);
     cin>>q;
     while(q--)
     {
          cin>>x>>y>>z;
          if(x==0)
          {
               update(0,0,n-1,y-1,y-1,z);
          }
          else if(x==1)
          {
               int see = z-y+1;
               cout<<see-query(0,0,n-1,y-1,z-1)<<endl;
          }
          else
          {
               cout<<query(0,0,n-1,y-1,z-1)<<endl;
          }
     }
}	
