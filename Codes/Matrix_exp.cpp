vector<vector<int>> mul(vector<vector<int>> a,vector<vector<int>> b)
{
     int n = a.size();
     vector<vector<int>> ans;
     ans.resize(n);
     for(int i=0;i<n;i++)
     {
          ans[i].resize(n);
          for(int j=0;j<n;j++)
          {
               ans[i][j]=0;
          }
     }
     for(int i=0;i<n;i++)
     {
          for(int j=0;j<n;j++)
          {
               for(int k=0;k<n;k++)
               {
                    ans[i][j] += (a[i][k]*b[k][j])%mod;
                    ans[i][j]%=mod;
               }
          }
     }
     return ans;
}

vector<vector<int>> exp(vector<vector<int>> x,int num)
{
     if(num==1)
          return x;
     int see = num/2;
     vector<vector<int>> y = exp(x,see);
     y = mul(y,y);
     if(num%2==1)
     {
          y = mul(y,x);
     }
     return y;
}






