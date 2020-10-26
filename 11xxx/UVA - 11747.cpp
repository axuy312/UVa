#include <iostream>
#include <queue>
//#include <fstream>

using namespace std;
struct Node
{
	int p, rank = 0;
};
struct Edge
{
	int u, v;
	int dis;
	bool operator>(const Edge& e)const {
		return dis > e.dis;
	}
};
vector<Node>nodes;
priority_queue<Edge, vector<Edge>, greater<Edge> >edges;
int FindSet(int n) {
	if (n != nodes[n].p)
	{
		nodes[n].p = FindSet(nodes[n].p);
	}
	return nodes[n].p;
}
int main() {
	//ofstream out("t.txt");
	int m, n, total;
	priority_queue<int, vector<int>, greater<int> >output;
	while (cin >> m >> n)
	{
		if (m == 0 && n == 0)
		{
			break;
		}
		bool* use = new bool[m]();
		total = 0;
		nodes.clear();
		nodes.resize(m + 1);
		while (!edges.empty())
		{
			edges.pop();
		}
		Edge newEdge;
		for (int i = 0; i < n; i++)
		{
			cin >> newEdge.u >> newEdge.v >> newEdge.dis;
			total += newEdge.dis;
			edges.push(newEdge);
		}
		//create edge each node to nodes
		for (int i = 0; i < m; i++)
		{
			nodes[i].p = i;
		}
		//debug

		/*int c = 0;
		while (!edges.empty())
		{
			Edge e = edges.top();
			edges.pop();
			cout << ++c << ": " << e.u << " -> " << e.v << endl;
		}*/
		while (!edges.empty())
		{
			int u = edges.top().u, v = edges.top().v;
			int dis = edges.top().dis;
			edges.pop();
			int rootU = FindSet(u), rootV = FindSet(v);
			if (rootU != rootV)
			{
				use[u] = use[v] = true;
				if (nodes[rootU].rank > nodes[rootV].rank)
				{
					nodes[rootV].p = rootU;
				}
				else
				{
					nodes[rootU].p = rootV;
					if (nodes[rootU].rank == nodes[rootV].rank)
					{
						nodes[rootV].rank++;
					}
				}
			}
			else
			{
				output.push(dis);
			}
		}
		if (output.empty())
		{
			cout << "forest";
		}
		else
		{
			cout << output.top();
			output.pop();
			while (!output.empty())
			{
				cout << " " << output.top();
				output.pop();
			}
		}
		cout << "\n";
	}

	//system("pause");
	return 0;
}