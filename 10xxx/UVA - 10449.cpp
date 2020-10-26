#include <iostream>

using namespace std;

struct Edge
{
	int u, v, t;
};
struct Node
{
	int d, b;
	bool max, vaild;
};

Node node[1001];
Edge edge[2001];

void BellmanFord(int n, int m) {
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
	for (int i = 0; i < n; i++){

		for (int j = 0; j < m; j++)
		{
			if (!node[edge[j].u].max && (node[edge[j].v].d > node[edge[j].u].d + edge[j].t || node[edge[j].v].max))
			{
				node[edge[j].v].d = node[edge[j].u].d + edge[j].t;
				node[edge[j].v].vaild = false;
			}
		}
	}
}

int main() {
	int n, m, t, q, c = 0;
	while (cin >> n)
	{
		//ofstream out("t.txt", ios::app);
		for (int i = 1; i <= n; i++)
		{
			cin >> node[i].b;
			node[i].max = node[i].vaild = true;
		}
		node[1].max = false;
		node[1].d = 0;
		cin >> m;
		for (int i = 0; i < m; i++)
		{
			cin >> edge[i].u >> edge[i].v;
			t = node[edge[i].v].b - node[edge[i].u].b;
			edge[i].t = t * t * t;
		}
		BellmanFord(n, m);
		cin >> q;
		cout << "Set #" << ++c << "\n";
		for (int i = 0; i < q; i++)
		{
			cin >> t;
			if (!node[t].vaild || node[t].max || node[t].max || node[t].d < 3)
			{
				cout << "?\n";
			}
			else
			{
				cout << node[t].d << "\n";
			}
		}
		//out.close();
	}
	return 0;
}