bool prime[N+1]; 
std::vector<int> prme;

void SieveOfEratosthenes(int n) 
{ 
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=n; p++) 
    { 
        if (prime[p] == true) 
        {     
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
  
    for (int p=2; p<=n; p++) 
       if (prime[p]) 
          prme.pb(p); 
} 

void init()
{
	SieveOfEratosthenes(200009);
}
