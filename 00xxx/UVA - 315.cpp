#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
//can't global varible
struct node
{
	bool counted;
	int num;
	int min;
	int pre;
};
void dfs(int u, int &numCritical, int &time, int &rootCount, vector< vector < int > >&connect, vector< node >&nodes) {
	nodes[u].num = nodes[u].min = time++;
	for (int i = 0; i < connect[u].size(); i++)
	{
		if (nodes[connect[u][i]].num == 0)
		{
			if (u == 1)
			{
				rootCount++;
			}
			nodes[connect[u][i]].pre = u;
			dfs(connect[u][i], numCritical, time, rootCount, connect, nodes);
			if (nodes[u].min > nodes[connect[u][i]].min)
			{
				nodes[u].min = nodes[connect[u][i]].min;
			}
			if (nodes[connect[u][i]].min >= nodes[u].num && u != 1 && !nodes[u].counted)
			{
				nodes[u].counted = true;
				numCritical++;
			}
		}
		else if(nodes[u].pre != connect[u][i])
		{
			if (nodes[u].min > nodes[connect[u][i]].num)
			{
				nodes[u].min = nodes[connect[u][i]].num;
			}
		}
	}

}

int main() {
	int numCritical, time, rootCount;
	vector< vector < int > >connect;
	vector< node >nodes;
	stringstream ss;
	string line;
	int num, vetex, point;
	while (cin >> num && num != 0)
	{
		time = 1;
		rootCount = 0;
		numCritical = 0;
		nodes.clear();
		nodes.resize(num + 1);
		connect.clear();
		connect.resize(num + 1);
		cin.clear();
		cin.ignore();
		while (getline(cin, line) && line[0] != '0')
		{
			ss.str("");
			ss.clear();
			ss << line;
			ss >> vetex;
			while (ss >> point)
			{
				connect[vetex].push_back(point);
				connect[point].push_back(vetex);
			}
		}
		dfs(1, numCritical, time, rootCount, connect, nodes);
		if (rootCount > 1)
		{
			numCritical++;
		}
		cout << numCritical << "\n";
	}
	return 0;
}