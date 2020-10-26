#include <iostream>
#include <queue>
#include <cmath>
//#include <fstream>

using namespace std;
struct Node
{
	int x, y, p, rank = 0;
};
struct Edge
{
	int u, v;
	double dis;
	bool operator>(const Edge& e)const {
		return dis > e.dis;
	}
};
vector<Node>nodes;
priority_queue<Edge, vector<Edge>, greater<Edge> >edges;
double distance(Node u, Node v) {
	return (sqrt(pow(u.x - v.x, 2) + pow(u.y - v.y, 2)));
}
int FindSet(int n) {
	if (n != nodes[n].p)
	{
		nodes[n].p = FindSet(nodes[n].p);
	}
	return nodes[n].p;
}
int main() {
	//ofstream out("t.txt");
	int numCase, n, r, x, y;
	cin >> numCase;
	for (int i = 0; i < numCase; i++)
	{
		cin >> n >> r;
		Edge newEdge;
		nodes.clear();
		nodes.resize(n);
		while (!edges.empty())
		{
			edges.pop();
		}
		for (int j = 0; j < n; j++)
		{
			cin >> nodes[j].x >> nodes[j].y;
			nodes[j].p = j;
		}
		//create edge each node to nodes
		for (int j = n - 1; j > 0; j--)
		{
			for (int k = 0; k < j; k++)
			{
				newEdge.u = k;
				newEdge.v = j;
				newEdge.dis = distance(nodes[k], nodes[j]);
				edges.push(newEdge);
				//newEdge.u = j;
				//newEdge.v = k;
				//edges.push(newEdge);
			}
		}
		//debug
		/*
		int c = 0;
		while (!edges.empty())
		{
			Edge e = edges.top();
			edges.pop();
			cout << ++c << ": " << nodes[e.u].x << ", " << nodes[e.u].y << " -> " << nodes[e.v].x << ", " << nodes[e.v].y << " : " << e.dis << endl;
		}*/
		double rail = 0, road = 0;
		int c = 1;
		while (!edges.empty())
		{
			int u = edges.top().u, v = edges.top().v;
			double dis = edges.top().dis;
			edges.pop();
			int rootU = FindSet(u), rootV = FindSet(v);
			if (rootU != rootV)
			{
				if (dis > r)
				{
					rail += dis;
					c++;
				}
				else
				{
					road += dis;
				}
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
		}
		cout << "Case #" << i + 1 << ": " << c << " " << round(road) << " " << round(rail) << "\n";
	}

	//system("pause");
	return 0;
}