//Miss Me??
#include<bits/stdc++.h>
using namespace std;
     
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define int long long int
#define pb push_back
#define endl "\n"
#define ff first
#define ss second
#define N 300009
#define mod 1000000007
#define cn continue
#define bre break
#define pr pair<int,int>

struct tree
{
    int prefix;
    int suffix;
    int sum;
    int ans;
    int max;
};

int n,m;
int a[N];
int x,y;
tree t[N];

void build(int s=0,int end=n-1,int node=0)
{
    if(s==end)
    {
        t[node].sum=a[s];
        if(a[s]>=0)
        {
            t[node].prefix=a[s];
            t[node].suffix=a[s];
            t[node].ans=a[s];
            t[node].max=a[s];
        }
        else
        {
            t[node].prefix=a[s];
            t[node].suffix=a[s];
            t[node].ans=a[s];
            t[node].max=a[s];
        }
        return;
    }
    int mid = (s+end)/2;
    build(s,mid,2*node+1);
    build(mid+1,end,2*node+2);
    t[node].sum=t[2*node+2].sum+t[2*node+1].sum;
    t[node].max=max(t[2*node+1].max,t[2*node+2].max);
    t[node].prefix=max(t[2*node+1].prefix,t[2*node+2].prefix+t[2*node+1].sum);
    t[node].suffix=max(t[2*node+2].suffix,t[2*node+1].suffix+t[2*node+2].sum);
    t[node].ans=max(t[2*node+1].suffix+t[2*node+2].prefix,t[2*node+1].ans);
    t[node].ans=max(t[node].ans,t[2*node+2].ans);
    t[node].ans=max(t[node].ans,t[node].max);
    //cout<<t[node].ans<<" "<<s<<" "<<end<<endl;
}

tree query(int node=0,int s=0,int e=n-1,int l=x,int r=y)
{
    tree bakwaas;
    bakwaas.ans=-2e10;
    bakwaas.sum=-2e10;
    bakwaas.max=-2e10;
    bakwaas.suffix=-2e10;
    bakwaas.prefix=-2e10;
    if(s>r||e<l)
        return bakwaas;
    if(s>=l&&r>=e)
    {
        return t[node];
    }
    int mid = (s+e)/2;
    tree left = query(2*node+1,s,mid,l,r);
    tree right = query(2*node+2,mid+1,e,l,r);
    tree ans;
    ans.sum=left.sum+right.sum;
    ans.max=max(left.max,right.max);
    ans.prefix=max(left.prefix,right.prefix+left.sum);
    ans.suffix=max(right.suffix,left.suffix+right.sum);
    ans.ans=max(left.suffix+right.prefix,left.ans);
    ans.ans=max(ans.ans,right.ans);
    ans.ans=max(ans.ans,ans.max);
    return ans;
}

signed main()
{
    boost;
    cin>>n;
    for(int i=0;i<n;i++) 
    {
        cin>>a[i];
    }
    build();
    cin>>m;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        x--,y--;
        cout<<query().ans<<endl;
    }
}   
