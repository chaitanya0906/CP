//https://www.interviewbit.com/problems/very-hard-queries/

#define mod 1000000007
void init(vector<int> &sqr)
{
        int i = 1;
        for (; i <= 1000; i++)
        {
                sqr.push_back(i * i);
        }
}

int calc(int x, vector<int> &sq)
{
        int is = lower_bound(sq.begin(), sq.end(), x) - sq.begin();
        int ans = abs(x - sq[is]);
        //ans = min(ans, abs(sq[is + 1] - x));
        for (int i = max(is - 6, 0); i < min((int)sq.size(), is + 7); i++)
        {
                ans = min(ans, abs(x - sq[i]));
        }
        return ans;
}

void build(vector<int> &T, vector<int> &A, int l, int r, int plac)
{
        if (l == r)
        {
                T[plac] = A[l];
                return;
        }
        if (l > r)
                return;
        int mid = (l + r) / 2;
        build(T, A, l, mid, 2 * plac + 1);
        build(T, A, mid + 1, r, 2 * plac + 2);
        T[plac] = T[plac * 2 + 1] + T[plac * 2 + 2];
}

void update(vector<int> &T, int l, int r, int plac, int idx, int val)
{
        if (l > r)
                return;
        if (l == r)
        {
                T[plac] = val;
                return;
        }
        int mid = (l + r) / 2;
        if (idx <= mid && idx >= l)
                update(T, l, mid, plac * 2 + 1, idx, val);
        if (idx <= r && idx > mid)
                update(T, mid + 1, r, plac * 2 + 2, idx, val);
        T[plac] = T[plac * 2 + 1] + T[plac * 2 + 2];
}

int query(vector<int> &T, int l, int r, int plac, int s, int e)
{
        if (l > e)
                return 0;
        if (r < s)
                return 0;
        if (l > r)
                return 0;
        if (l == r)
        {
                return T[plac];
        }
        if (l >= s && r <= e)
                return T[plac];
        int mid = (l + r) / 2;
        int ans = query(T, l, mid, 2 * plac + 1, s, e) + query(T, mid + 1, r, 2 * plac + 2, s, e);
        return ans;
}

int Solution::solve(vector<int> &A, vector<vector<int>> &B)
{

        vector<int> sqr;

        init(sqr);

        vector<int> T;
        T.resize(4 * A.size() + 100, 0);

        vector<int> ne;
        for (int i = 0; i < A.size(); i++)
        {
                ne.push_back(calc(A[i], sqr));
        }
        build(T, ne, 0, A.size() - 1, 0);
        long long int ans = 0;

        for (int i = 0; i < B.size(); i++)
        {
                int q = B[i][0];
                if (q == 1)
                {
                        int id, x;
                        id = B[i][1];
                        x = B[i][2];
                        id--;
                        update(T, 0, A.size() - 1, 0, id, calc(x, sqr));
                }
                else
                {
                        int l, r;
                        l = B[i][1];
                        r = B[i][2];
                        l--;
                        r--;
                        int n = A.size();
                        ans += (long long int)query(T, 0, n - 1, 0, l, r);
                        ans %= mod;
                        //cout<<query(T, 0, n-1, 0,l,r)<<endl;
                }
        }

        return ans;
}
