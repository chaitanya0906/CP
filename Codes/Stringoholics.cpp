#define mod 1000000007
 
long long int kmp(string s)
{
        int n = s.length();
        vector<long long int> lps;
        lps.resize(n, 0);
        lps[0] = 0;
        long long int i = 1;
        long long int len = 0;
        while (i < n)
        {
                if (s[i] == s[len])
                {
                        len++;
                        lps[i] = len;
                        i++;
                        
                }
                else
                {
                        if (len != 0)
                        {
                                len = lps[len - 1];
                        }
                        else
                        {
                                lps[i] = 0;
                                i++;
                        }
                }
        }
        len = lps[n - 1];
        long long int ans = n - len;
        if (n % ans == 0)
        {
                if (len == 0)
                {
                        return n;
                }
                else
                {
                        return ans;
                }
        }
        return n;
}
 
long long int calc(long long int see)
{
        long long int i = 1;
        long long int nw = 1;
        while (!(i % see == 0))
        {
                nw++;
                i += nw;
        }
        return nw;
}
 
 
void sieve(vector<long long int> &pri)
{
        pri.resize(100009);
        pri[1] = 1;
        int n = pri.size();
        for(long long int i=2;i<n;i++)
        {
                pri[i] = i;
        }
 
        for(long long int i=2;i<n;i++)
        {
                if(pri[i]==i)
                {
                        for(long long int j=i*i;j<n;j+=i)
                        {
                                pri[j] = i;
                        }
                }
        }
 
}
 
long long int powi(long long int a,long long int b)
{
        if(b==0)
                return 1;
        long long int de = powi(a,b/2);
        de*=de;
        de%=mod;
        if(b%2==1)
        {
                de*=a;
        }
        de%=mod;
        return de;
}
 
long long int lcm(vector<long long int> see)
{
        vector<long long int> pri;
    //cout<<"hi\n";
        sieve(pri);
 
    //cout<<"hi\n";
        map<long int,long long int> mp;
        for(long long int i=0;i<see.size();i++)
        {
                map<long int,long long int> local;
                while(see[i]>1)
                {
                        local[pri[see[i]]]++;
                        if(local[pri[see[i]]]>mp[pri[see[i]]])
                                mp[pri[see[i]]] = local[pri[see[i]]];
                        see[i]/=pri[see[i]];
                }
        }
    //cout<<"angaea\n";
        long long int ans = 1; 
        for(auto i:mp)
        {
                ans*= powi(i.first,i.second);
                ans%=mod;
        }
        return ans;
}
 
 
 
int Solution::solve(vector<string> &A)
{
        vector<long long int> dekh;
        int n = A.size();
        for (int i = 0; i < n; i++)
        {
                dekh.push_back(kmp(A[i]));
        }
        long long int ans = 1;
        vector<long long int> req;
 
        for (int i = 0; i < n; i++)
        {
                req.push_back(calc(dekh[i]));
        }
 
        ans = lcm(req);
        
        return ans;
}