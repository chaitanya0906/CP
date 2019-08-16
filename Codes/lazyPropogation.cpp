// Max in Range

#include <bits/stdc++.h>
using namespace std;

#define N 100009

int n;
int a[N], tree[4 * N + 2], lazy[8 * N + 2];
int q;
int x, y, val;

void build(int l, int r, int idx)
{
        if (l == r)
        {
                tree[idx] = a[l];
                return;
        }
        int mid = (l + r) / 2;

        build(l, mid, 2 * idx + 1);
        build(mid + 1, r, 2 * idx + 2);

        tree[idx] = max(tree[2 * idx + 1], tree[2 * idx + 2]);
}

void update(int l, int r, int s, int e, int idx, int val)
{
        if (l > e || r < s)
        {
                return;
        }
        int mid = (l + r) / 2;

        if (l >= s && r <= e && (l != r))
        {
                tree[idx] += val;
                lazy[2 * idx + 1] += val;
                lazy[2 * idx + 2] += val;
                return;
        }

        else if (l >= s && r <= e)
        {
                tree[idx] += val;
                return;
        }

        update(l, mid, s, e, 2 * idx + 1, val);
        update(mid + 1, r, s, e, 2 * idx + 2, val);

        tree[idx] = max(tree[2 * idx + 1], tree[2 * idx + 2]);

        cout << tree[idx] << " is the answer fot the range " << l << " " << r << endl;
}

int query(int l, int r, int s, int e, int idx)
{
        if (l > e || r < s)
        {
                return INT_MIN;
        }

        if (lazy[idx] != 0)
        {
                tree[idx] += lazy[idx];
                lazy[idx] = 0;
                lazy[2 * idx + 1] += val;
                lazy[2 * idx + 2] += val;
        }

        if (l >= s && r <= e)
        {
                return tree[idx];
        }

        int mid = (l + r) / 2;

        int a = query(l, mid, s, e, 2 * idx + 1);
        int b = query(mid + 1, r, s, e, 2 * idx + 2);

        return max(a, b);
}

int main()
{
        cin >> n;

        memset(tree, 0, sizeof(tree));
        memset(lazy, 0, sizeof(lazy));

        for (int i = 0; i < n; i++)
        {
                cin >> a[i];
        }

        build(0, n - 1, 0);

        cin >> q;

        while (q--)
        {
                cin >> x >> y >> val;
                update(0, n - 1, x, y, 0, val);
        }

        // for (int i = 0; i < n; i++)
        // {
        //         for (int j = i; j < n; j++)
        //         {
        //                 cout << query(0, n - 1, i, j, 0) << " is ans for range " << i << " " << j << endl;
        //         }
        // }
}