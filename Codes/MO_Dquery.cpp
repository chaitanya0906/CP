    #include<bits/stdc++.h>
    using namespace std;
         
    #define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
    //#define int long long int
    #define pb push_back
    #define endl "\n"
    #define ff first
    #define ss second
    #define N 300009
    #define M 103
    #define mod 1000000007
    #define med 998244353
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
     
    int n,q;
    int a[N];
    pair<pr,int> p[N];
    int cnt[1000009];
    int answer;
    int ans[N];
    int bck_sz;
     
    bool cmp(pair<pr,int> a,pair<pr,int> b)
    {
        int  i,j;
        i=a.ff.ss/bck_sz;
        j=b.ff.ss/bck_sz;
        if(i==j)
        {
            if(a.ff.ff<b.ff.ff)
                return 1;
            else
                return 0;
        }
        else{
            if(i<j)
                return 1;
            else
                return 0;
        }
    }
     
    void add(int x)
    {
        if(cnt[a[x]]==0)
        {
            answer++;
        }
        //cout<<a[x]<<endl;
        cnt[a[x]]++;
    }
     
    void remove(int x)
    {
        if(cnt[a[x]]==1)
        {
            answer--;
        }
        cnt[a[x]]--;
    }   
     
    int32_t main()
    {
        IOS;
        memset(cnt,0,sizeof(cnt));
        scanf("%d",&n);
        bck_sz = sqrt(n);
        for(int i=0;i<n;i++)
        {
             scanf("%d",&a[i]);
        }
        scanf("%d",&q);
        for(int i=0;i<q;i++)
        {
            scanf("%d %d",&p[i].ff.ff,&p[i].ff.ss);
            p[i].ff.ff--;
            p[i].ff.ss--;
            p[i].ss=i;
        }
        sort(p,p+q,cmp);
        int l=0;
        int r=0;
        answer=1;
        cnt[a[0]]=1;
        for(int i=0;i<q;i++)
        {
            while(l<p[i].ff.ff)
            {
                remove(l);
                l++;      
                //cout<<l<<" removed"<<endl;     
            }
            while(r<p[i].ff.ss)
            {
                r++;
                add(r);
            }
            while(l>p[i].ff.ff)
            {
                l--;
                add(l);
            }
            while(r>p[i].ff.ss)
            {
                remove(r);
                r--;
            }
            ans[p[i].ss]=answer;
            //cout<<p[i].ff.ff<<" "<<p[i].ff.ss<<" "<<answer<<endl;
        }
        for(int i=0;i<q;i++)
        {
             printf("%d\n",ans[i]);
        }
    }  
