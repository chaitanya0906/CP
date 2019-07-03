/*
  https://codeforces.com/contest/960/problem/F
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
#define mod 1000000007
#define med 998244353
#define dbg cout<<"There There\n";
#define dbg1(x) cout<<"\nValue is "<<x<<endl
#define dbg2(x,y) cout<<"\nValue is "<<x<<" "<<y<<endl
#define dbg3(x,y,z) cout<<"\nValue is "<<x<<" "<<y<<" "<<z<<endl  
#define pq priority_queue<int>
#define mpq priority_queue<int,vector<int>,greater<int>>
#define pr pair<int,int>
#define mx INT_MAX
#define lmx LLONG_MAX
#define err return 0
#define cn continue 
#define bre break

int n,m;
int x,y,z;

struct node
{
     int val;
     node* l;
     node* r;
     node()
     {
          val = 0;
          l = NULL;
          r = NULL;
     }
};

node *tree[N];

int query(node* curr,int s,int e,int l,int r)
{
     if(curr == NULL ||s>r || e < l)
          return 0;
     else  if(l<=s && e<=r)
          return curr->val;
     int mid = (s+e)/2;
     return max(query(curr->l,s,mid,l,r),query(curr->r,mid+1,e,l,r));    
}

void update(node* curr,int s,int e,int idx,int val)
{
     if(s==e)
     {
          curr->val = max(curr->val,val);
          return ;
     }
     int mid = (s+e)/2;
     if(idx<=mid)
     {
          if(curr->l==NULL)
               curr->l = new node();
          update(curr->l,s,mid,idx,val);
          curr->val = max(curr->val,curr->l->val);
     }
     else
     {
          if(curr->r==NULL)
               curr->r = new node();
          update(curr->r,mid+1,e,idx,val);
          curr->val = max(curr->val,curr->r->val);
     }
}    

int32_t main()
{
	IOS;
     cin>>n>>m;
     for(int i=1;i<=N;i++)
     {
          tree[i] = new node();
     }
     int ans=0;
     while(m--)
     {
          cin>>x>>y>>z;
          int val = query(tree[x],0,100000,0,z-1);
          //dbg1(val);
          ans = max(ans,val+1);
          update(tree[y],0,100000,z,val+1);
     }
     cout<<ans<<endl;
}			
