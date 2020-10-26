#include <iostream>
#include <fstream>

using namespace std;

struct Edge
{
	int u, v, t;
};
struct Node
{
	int d, pi;
	bool max;
};

Node node[1001];
Edge edge[2001];

bool BellmanFord(int n, int m) {
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			//cout << edge[j].u << " -> " << edge[j].v << "\n";
			//cout << node[edge[j].u].max << " " << node[edge[j].v].max << "\n";
			//cout << node[edge[j].u].d << " + " << edge[j].t << " " << node[edge[j].v].d << "\n";
			if (!node[edge[j].u].max && (node[edge[j].v].d > node[edge[j].u].d + edge[j].t || node[edge[j].v].max))
			{
				node[edge[j].v].d = node[edge[j].u].d + edge[j].t;
				node[edge[j].v].max = false;
			}
		}
	}
	for (int j = 0; j < m; j++)
	{
		if (!node[edge[j].u].max && (node[edge[j].v].d > node[edge[j].u].d + edge[j].t || node[edge[j].v].max))
		{
			return false;
		}
	}
	return true;
}

int main() {
	ofstream out("t.txt");
	int c, n, m, num = 0;
	cin >> c;
	while (c--)
	{
		cin >> n >> m;
		//cout << ++num << "\n";
		for (int i = 0; i < m; i++)
		{
			cin >> edge[i].u >> edge[i].v >> edge[i].t;
		}
		for (int i = 0; i < n; i++)
		{
			node[i].max = true;
		}
		node[0].max = false;
		node[0].d = 0;
		if (BellmanFord(n, m))
		{
			cout << "not possible\n";
		}
		else
		{
			cout << "possible\n";
		}
	}
	return 0;
}