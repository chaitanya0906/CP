class Solution {
public:
    string longestPalindrome(string s) 
    {
        int n = s.length();
        vector<char> see;
        see.push_back('#');
        for(int i=0;i<s.length();i++)
        {
            see.push_back(s[i]);
            see.push_back('#');
        }
        int p[2*n+1];
        memset(p,0,sizeof(p));
        int c=0;
        int r=0;
        for(int i=0;i<2*n+1;i++)
        {
            int mirror = c-(i-c);
            if(r>i)
            {
                p[i] = min(r-i,p[mirror]);
            }
            else
            {
                p[i] = 0;
            }
            while((i+1+p[i])<2*n+1&&(i-1-p[i])>=0&&see[i+1+p[i]]==see[i-1-p[i]])
            {
                p[i]++;
            }
            if(i+p[i]>r)
            {
                c = i;
                r = i + p[i];
            }
        }
        int maxi = -1;
        for(int i=0;i<2*n+1;i++)
        {
            if(p[i]>maxi)
            {
                c = i;
                maxi = p[i];
            }
        }
        vector<char> ans;
        int left = c-maxi;
        int right = c+maxi;
        for(int i=left;i<=right;i++)
        {
            if(see[i]=='#')
            {
                continue;
            }
            ans.push_back(see[i]);
        }
        string str(ans.begin(),ans.end());
        return str;
    }
};
