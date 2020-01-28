int n, l, a, b;
vector<vector<int>> adj;
vector<vector<int>> up;

// Binary Lifting
void dfs(int v, int p)
{
	up[v][0] = p;
	for (int i = 1; i <= l; ++i)
		up[v][i] = up[up[v][i - 1]][i - 1];
	for (int u : adj[v])
		if (u != p)
			dfs(u, v);
}

void preprocess(int root)
{
	l = ceil(log2(n));
	up.assign(n, vector<int>(l + 1));
	dfs(root, root);
}
