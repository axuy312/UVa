#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define N 1010

int n, m;
int dfn[N], low[N], vis[N], de[N], bcn, dfs_clock;
vector<int>connect[N];

void dfs(int u, int pre) {
	low[u] = dfn[u] = ++dfs_clock;
	vis[u] = 1;
	for (int i = 0; i < connect[u].size(); i++)
	{
		int v = connect[u][i];
		if (vis[v] == 0)
		{
			dfs(v, u);
			low[u] = min(low[u], low[v]);
			if (low[u] < low[v])
			{
				bcn++;
			}
		}
		else if (v != pre)
		{
			low[u] = min(low[u], dfn[v]);
		}
	}
}

int main() {
	while (cin >> n >> m)
	{
		dfs_clock = bcn = 0;
		for (int i = 1; i <= n; i++)
		{
			connect[i].clear();
			vis[i] = 0;
		}
		while (m--)
		{
			int u, v;
			cin >> u >> v;
			connect[u].push_back(v);
			connect[v].push_back(u);
		}
		for (int i = 1; i <= n; i++)
		{
			if (vis[i] == 0)
			{
				dfs(i, -1);
				bcn++;
			}
		}
		if (bcn == 1)
		{
			cout << "0\n";
		}
		else
		{
			int res = 0;
			for (int i = 0; i <= n; i++)
			{
				de[i] = 0;
			}
			bool used[N] = {};
			for (int i = 1; i <= n; i++)
			{
				if (connect[i].empty())
				{
					used[low[i]] = true; continue;
				}
				for (int j = 0; j < connect[i].size(); j++)
				{
					used[low[i]] = used[low[connect[i][j]]] = true;
					if (low[i] != low[connect[i][j]])
					{
						de[low[i]]++;
					}
				}
			}
			for (int i = 1; i <= n; i++)
			{
				if (used[i] && de[i] == 0)
				{
					res += 2;
				}
				else if (de[i] == 1)
				{
					res++;
				}
			}
			cout << (res + 1) / 2 << '\n';

		}
	}
	return 0;
}