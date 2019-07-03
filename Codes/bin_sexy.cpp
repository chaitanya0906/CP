/*https://codeforces.com/problemset/problem/1156/C */

#include<bits/stdc++.h>
using namespace std;
     
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long int
#define pb push_back
#define endl "\n"
#define ff first
#define ss second
#define N 200009
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

int n,z;
int x[N];

bool check(int see)
{
	int piche = n-see;
	for(int i=0;i<see;i++,piche++)
	{
		if(x[piche]-x[i]<z)
			return 0;
	}	
	return 1;
}

int32_t main()
{
	IOS;
	cin>>n>>z;
	for(int i=0;i<n;i++)
	{
		cin>>x[i];
	}
	sort(x,x+n);
	int l = 0;
	int r = n/2;
	while(l<r)
	{
		if(l==r-1)
		{
			if(check(r))
			{
				l=r;
			}
			break;
		}
		int mid = (l+r)/2;
		if(check(mid))
		{
			l=mid;
		}
		else
		{
			r=mid;
		}
	}
	cout<<l<<endl;
	return 0;
}	
