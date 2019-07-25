// https://www.interviewbit.com/problems/median-of-array/

double find(const vector<int> &A, const vector<int> &B)
{
        int n = A.size();
        int m = B.size();
        //A.push_back(INT_MAX);
        //B.push_back(INT_MAX);
        //cout << "HERE\n";
        double ans;
        if (n > m)
        {
                return find(B, A);
        }
        int partl = 0;
        int partr = n;
        while (partl <= partr)
        {
                int mid = (partl + partr) / 2;
                //cout << partl << " " << partr << endl;
                int niche_partition = ((n + m + 1) / 2) - mid;
                int l1, l2, r1, r2;
                if (mid == 0)
                {
                        l1 = INT_MIN;
                }
                else
                {
                        l1 = A[mid - 1];
                }
                if (niche_partition == 0)
                {
                        l2 = INT_MIN;
                }
                else
                {
                        l2 = B[niche_partition - 1];
                }
                if (mid < n)
                        r1 = A[mid];
                else
                        r1 = INT_MAX;
                if (niche_partition < m)
                        r2 = B[niche_partition];
                else
                        r2 = INT_MAX;
                //cout << l1 << " " << l2 << " " << r1 << " " << r2 << endl;
                if (l1 <= r2 && l2 <= r1)
                {
                        if ((n + m) % 2 == 0)
                        {
                                double see = max(l1, l2);
                                double see1 = min(r1, r2);
                                //cout << see << " adada " << see1 << endl;
                                return (see + see1) / 2;
                        }
                        else
                        {
                                return max(l1, l2);
                        }
                }
                else if (l2 > r1)
                {
                        partl = mid + 1;
                }
                else
                {
                        partr = mid - 1;
                }
        }
}
double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B)
{
        return find(A, B);
}
