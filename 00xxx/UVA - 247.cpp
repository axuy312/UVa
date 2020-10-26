#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

vector<int>connect[30];
vector<int>scc[30];
map<string, int>position;
vector<int>dfs_stack;
string findName[30];
bool vis[30];
bool in_stack[30] = {};
int low[30], dfn[30], dfs_clock, n_scc = 0;

void dfs(int u) {
	low[u] = dfn[u] = ++dfs_clock;
	dfs_stack.push_back(u);
	in_stack[u] = vis[u] = true;
	for (int i = 0; i < connect[u].size(); i++)
	{
		if (!vis[connect[u][i]])
		{
			//nodes[connect[u][i]].pre = u;
			dfs(connect[u][i]);
			low[u] = min(low[u], low[connect[u][i]]);
		}
		else if (in_stack[connect[u][i]])
		{
			low[u] = min(low[u], dfn[connect[u][i]]);
		}
	}
	if (low[u] == dfn[u])
	{
		int pop;
		do
		{
			pop = dfs_stack.back();
			scc[n_scc].push_back(pop);
			in_stack[pop] = false;
			dfs_stack.pop_back();
		} while (pop != u);
		++n_scc;
	}
}
int main() {
	int n, m, c, numcase = 0;
	string call, callto;
	while (cin >> n >> m)
	{
		if (n == 0 && m == 0)
		{
			break;
		}
		for (int i = 1; i <= n; i++)
		{
			findName[i] = "";
			dfn[i] = low[i] = 0;
		}
		for (int i = 0; i < n_scc; i++)
		{
			scc[i].clear();
		}
		c = dfs_clock = n_scc = 0;
		position.clear();
		dfs_stack.clear();
		for (int i = 1; i <= n; i++)
		{
			connect[i].clear();
			vis[i] = false;
		}
		while (m--)
		{
			cin >> call >> callto;
			if (position[call] == 0)
			{
				position[call] = ++c;
				findName[c] = call;
			}
			if (position[callto] == 0)
			{
				position[callto] = ++c;
				findName[c] = callto;
			}
			connect[position[call]].push_back(position[callto]);
		}
		for (int i = 1; i <= n; i++)
		{
			if (!dfn[i])
			{
				dfs(i);
			}
		}
		if (numcase != 0)
		{
			cout << "\n";
		}
		cout << "Calling circles for data set " << ++numcase << ":\n";
		for (int i = 0; i < n_scc; i++)
		{
			cout << findName[scc[i][0]];
			for (int j = 1; j < scc[i].size(); j++)
			{
				cout << ", " << findName[scc[i][j]];
			}
			cout << "\n";
		}
	}
	system("pause");
	return 0;
}
