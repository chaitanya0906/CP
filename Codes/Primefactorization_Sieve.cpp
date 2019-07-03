void sieve()
{
     pro[1] = 1; 
     for(int i=1;i<M;i++)
     {
          prime[i] = 1;
     }
     prime[1] = 0;
     for(int i=2;i<M;i++)
     {
          if(prime[i]==1)
          {
               if(i<4000)          
               {    
                    for(int j=i*i;j<M;j+=i)
                    {
                         prime[j] = 0;
                         pro[j] = i;
                    }
               }
               pro[i] = i;
          }
     }
}
