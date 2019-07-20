//https://www.interviewbit.com/problems/word-break-ii/

vector<string> Solution::wordBreak(string A, vector<string> &B)
{
        map<string, bool> mp;
        int n = B.size();
        for (int i = 0; i < n; i++)
        {
                mp[B[i]] = 1;
        }

        vector<string> ans;

        string see = "";
        while (A.length() > 1)
        {
                see += A[0];
                A.erase(A.begin());
                if (mp[see])
                {
                        vector<string> dekh = wordBreak(A, B);
                        for (int i = 0; i < dekh.size(); i++)
                        {
                                dekh[i] = (see + " ") + dekh[i];
                        }
                        for (int i = 0; i < dekh.size(); i++)
                        {
                                ans.push_back(dekh[i]);
                        }
                }
        }

        see += A[0];
        if (mp[see])
        {
                ans.push_back(see);
        }
        return ans;
}
