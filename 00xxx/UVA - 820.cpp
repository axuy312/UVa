#include <iostream>
#include <queue>
#include <algorithm>
//#include <fstream>
using namespace std;

int main() {
	//ofstream out ("t.txt");
	int numNode, s, t, c, u, v, b, flow, numCase = 0;
	while (cin >> numNode)
	{
		if (numNode == 0)
		{
			break;
		}
		int bw[101][101] = {};
		flow = 0;
		cin >> s >> t >> c;
		for (int i = 0; i < c; i++)
		{
			cin >> u >> v >> b;
			bw[u][v] += b;
			bw[v][u] += b;
		}


		while (true)
		{
			//§ä¸ô®|
			int path[101] = {};
			queue<int>bfsQ;
			bfsQ.push(s);
			while (!bfsQ.empty())
			{
				int now = bfsQ.front();
				if (now == t)
				{
					break;
				}
				bfsQ.pop();
				for (int i = 0; i < 101; i++)
				{
					if (!path[i] && bw[now][i] > 0)
					{
						bfsQ.push(i);
						path[i] = now;
					}
				}
			}
			if (!path[t])
			{
				break;
			}
			int minF = bw[path[t]][t];
			for (int i = t; i != s; i = path[i])
			{
				minF = min(minF, bw[path[i]][i]);
			}
			for (int i = t; i != s; i = path[i])
			{
				bw[path[i]][i] -= minF;
				bw[i][path[i]] += minF;
			}
			/*for (int i = 1; i <= numNode; i++)
			{
				cout << i;
				for (int j = 0; j < 101; j++)
				{
					if (bw[i][j] > 0)
					{
						cout << "  (" << j << ")" << bw[i][j];
					}
				}
				cout << "\n";
			}*/
			flow += minF;
		}
		cout << "Network " << ++numCase << "\nThe bandwidth is " << flow << ".\n\n";
	}
	return 0;
}