//https://www.interviewbit.com/problems/coins-in-a-line/

int Solution::maxcoin(vector<int> &A)
{

        vector<vector<int>> ans;
        int n = A.size();
        ans.resize(n);

        for (int i = 0; i < n; i++)
        {
                ans[i].resize(n);
        }

        for (int i = 0; i < n; i++)
        {
                ans[i][i] = A[i];
        }

        for (int i = 0; i < (n - 1); i++)
        {
                ans[i][i + 1] = max(A[i], A[i + 1]);
        }

        for (int i = 3; i <= n; i++)
        {
                for (int j = 0; j < n; j++)
                {
                        int k = j + i - 1;

                        if (k >= n)
                                break;

                        ans[j][k] = max(A[j] + min(ans[j + 2][k], ans[j + 1][k - 1]), A[k] + min(ans[j][k - 2], ans[j + 1][k - 1]));
                        //int ans[]
                }
        }

        return ans[0][n - 1];
}
