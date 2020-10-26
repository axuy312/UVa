#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <stdlib.h>

using namespace std;

struct node
{
	int pre;
	int num;
	int min;
};

void dfs(vector< vector<int> >&connect, vector<node>&nodes, vector<set<int>>&critical, int u, int &time, int &numCritical) {
	nodes[u].num = nodes[u].min = ++time;
	for (int i = 0; i < connect[u].size(); i++)
	{
		//cout << u << " -> " << connect[u][i] << endl;
		if (nodes[connect[u][i]].num == 0)
		{
			nodes[connect[u][i]].pre = u;
			dfs(connect, nodes, critical, connect[u][i], time, numCritical);
			if (nodes[connect[u][i]].min < nodes[u].min)
			{
				nodes[u].min = nodes[connect[u][i]].min;
			}
			if (nodes[u].num < nodes[connect[u][i]].min)
			{
				numCritical++;
				if (u < connect[u][i])
				{
					critical[u].insert(connect[u][i]);
				}
				else
				{
					critical[connect[u][i]].insert(u);
				}
			}
		}
		else if (nodes[u].pre != connect[u][i])
		{
			if (nodes[connect[u][i]].num < nodes[u].min)
			{
				nodes[u].min = nodes[connect[u][i]].num;
			}
		}
	}
}

int main() {
	string line, nstr;
	int num, vetex, point, nint, time, numCritical;
	vector< vector<int> >connect;
	vector<node>nodes;
	vector<set<int>>critical;
	while (cin >> num)
	{
		time = numCritical = 0;
		critical.clear();
		critical.resize(num);
		nodes.clear();
		nodes.resize(num);
		connect.clear();
		connect.resize(num);
		cin.clear();
		cin.ignore();
		while (num--)
		{
			cin >> vetex >> nstr;
			nstr.pop_back();
			nstr.erase(nstr.begin());
			nint = atoi(nstr.c_str());
			for (int i = 0; i < nint; i++)
			{
				cin >> point;
				connect[vetex].push_back(point);
			}
		}
		num = connect.size();
		for (int i = 0; i < num; i++)
		{
			if (nodes[i].num == 0)
			{
				dfs(connect, nodes, critical, i, time, numCritical);
			}
		}
		cout << numCritical << " critical links\n";
		for (int i = 0; i < critical.size(); i++)
		{
			for (set<int>::iterator it = critical[i].begin(); it != critical[i].end(); ++it)
			{
				cout << i << " - " << *it << "\n";
			}
		}
		cout << "\n";
	}
	system("pause");
	return 0;
}
