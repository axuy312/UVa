#include <iostream>
//#include <fstream>
using namespace std;

struct Edge
{
	int u, v;
};
struct Node
{
	int d, e;
	bool min;
};

Node node[101] = {};
Edge edge[10001] = {};

void BellmanFord(int n, int m) {
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			//cout << edge[j].u << " -> " << edge[j].v << "\n";
			//cout << node[edge[j].u].min << " " << node[edge[j].v].min << "\n";
			//cout << node[edge[j].u].d << " + " << node[edge[j].v].e << " " << node[edge[j].v].d << "\n";
			if (!node[edge[j].u].min && (node[edge[j].v].d < node[edge[j].u].d + node[edge[j].v].e || node[edge[j].v].min) && node[edge[j].u].d + node[edge[j].v].e > 0)
			{
				node[edge[j].v].d = node[edge[j].u].d + node[edge[j].v].e;
				node[edge[j].v].min = false;
				if (!node[n].min)
				{
					return;
				}
			}
		}
	}
	int c = 10000 * n;
	bool change = true;
	while (c != 0 && change)
	{
		c--;
		change = false;
		for (int j = 0; j < m; j++)
		{
			if (!node[edge[j].u].min && (node[edge[j].v].d < node[edge[j].u].d + node[edge[j].v].e || node[edge[j].v].min) && node[edge[j].u].d + node[edge[j].v].e > 0)
			{
				node[edge[j].v].d = node[edge[j].u].d + node[edge[j].v].e;
				node[edge[j].v].min = false;
				change = true;
				if (!node[n].min)
				{
					return;
				}
			}
		}
	}
}

int main() {
	//ofstream out("t.txt");
	int n, m, energy, num, room;
	while (cin >> n && n != -1)
	{
		m = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> energy >> num;
			node[i].e = energy;
			while (num--)
			{
				edge[m].u = i;
				cin >> edge[m].v;
				m++;
			}
		}
		for (int i = 1; i <= n; i++)
		{
			node[i].min = true;
		}
		node[1].min = false;
		node[1].d = 100;
		BellmanFord(n, m);
		if (node[n].min)
		{
			cout << "hopeless\n";
		}
		else
		{
			cout << "winnable\n";
		}
	}
	return 0;
}