#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
#include <fstream>

using namespace std;
struct node
{
	int d, low;
};

void dfs(int u,int& clock, vector<vector<int>>connect, vector<bool>&used, map<int, bool>&in_edge,vector<node>&nodes,vector<int>&sccNum,stack<int>&scc) {
	nodes[u].d = nodes[u].low = ++clock;
	scc.push(u);
	for (int i = 0; i < connect[u].size(); i++)
	{
		if (nodes[connect[u][i]].d == 0)
		{
			dfs(connect[u][i], clock, connect, used, in_edge, nodes, sccNum, scc);
		}
		if (!used[connect[u][i]])
		{
			nodes[u].low = min(nodes[u].low, nodes[connect[u][i]].low);
		}
		else
		{
			in_edge[sccNum[connect[u][i]]] = false;
		}
	}
	if (nodes[u].d == nodes[u].low)
	{
		in_edge[nodes[u].d] = true;
		int pop;
		//cout << "COMPONENT: \n";
		do
		{
			pop = scc.top();
			used[pop] = true;
			//cout << pop << " ";
			sccNum[pop] = nodes[u].low;
			scc.pop();
		} while (pop != u);
		//cout << '\n';
	}
}

int main() {
	ofstream out("r.txt");
	vector<vector<int>>connect;
	vector<bool>used;
	map<int, bool>in_edge;
	vector<node>nodes;
	vector<int>sccNum;
	stack<int>scc;

	int clock;
	int numcase, x, y, n, m;
	cin >> numcase;
	while (numcase--)
	{
		cin >> n >> m;
		clock = 0;
		connect.clear();
		connect.resize(n + 1);
		nodes.clear();
		nodes.resize(n + 1);
		in_edge.clear();
		sccNum.clear();
		sccNum.resize(n + 1);
		used.clear();
		used.resize(n + 1);
		while (m--)
		{
			cin >> x >> y;
			connect[x].push_back(y);
		}
		for (int i = 1; i <= n; i++)
		{
			if (nodes[i].d == 0)
			{
				dfs(i, clock, connect, used, in_edge, nodes, sccNum, scc);
			}
		}
		int count = 0;
		for (map<int, bool>::iterator it = in_edge.begin(); it != in_edge.end(); ++it)
		{
			if (it->second)
			{
				count++;
			}
		}
		out << count << "\n";
	}
	system("pause");
	return 0;
}