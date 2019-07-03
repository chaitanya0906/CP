/*    https://www.spoj.com/problems/XMAX/            */

#include<bits/stdc++.h>
using namespace std;
     
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define int long long int
#define pb push_back
#define endl "\n"
#define ff first
#define ss second
#define N 300009
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

int n,k;
int a[N];
int powi[65];
vector<int> temp;

void init()
{
	powi[0]=1;
	for(int i=1;i<65;i++)
	{
		powi[i] = powi[i-1]*2;;
	}
}

int32_t main()
{
	IOS;
	init();
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int idx = 0;
	int plac;
	for(int i=63;i>=0;i--)
	{
		temp.clear();
		int maxi = -mx;
		plac = -1;
		for(int j=idx;j<n;j++)
		{
			if(powi[i]&a[j])
			{
				temp.pb(a[j]);
				if(maxi<a[j])
				{
					maxi = a[j];
					plac = j;
				}
			}	
		}
		if(plac==-1)
		{
			continue;
		}
		int temp = a[idx];
		a[idx] = a[plac];
		a[plac] = temp;
		for(int j=0;j<n;j++)
		{
			if(powi[i]&a[j]&&(j!=idx))
			{
				a[j] = a[j]^a[idx];
			}	
		}
		idx++;
	}
	int ans=0;
	int maxi = 0;
	for(int i=0;i<n;i++)
	{
		ans^=a[i];
		//cout<<a[i]<<endl;
	}
	cout<<ans<<endl;
}
