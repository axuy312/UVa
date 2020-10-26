#include <iostream>
#include <queue>

using namespace std;

vector<int>maze[101];
int weight[101][101], dis[101];

struct Node
{
	int vetex, weight;
	bool operator< (const Node& node)const{
		return weight > node.weight;
	}
};

int bfs(int n, int e, int t) {
	priority_queue<Node>que;
	Node u, v;
	u.vetex = e;
	u.weight = dis[e] = 0;
	que.push(u);
	while (!que.empty())
	{
		u = que.top();
		que.pop();
		for (int i = 0; i < maze[u.vetex].size(); i++)
		{
			if (u.weight + weight[u.vetex][maze[u.vetex][i]] < dis[maze[u.vetex][i]] || dis[maze[u.vetex][i]] == -1)
			{
				v.weight = dis[maze[u.vetex][i]] = u.weight + weight[u.vetex][maze[u.vetex][i]];
				v.vetex = maze[u.vetex][i];
				que.push(v);
			}
		}
	}
	int num = 0;
	for (int i = 1; i <= n; i++)
	{
		if (dis[i] <= t && dis[i] != -1)
		{
			num++;
		}
	}
	return num;
}

int main() {
	int numCase, N, T, E, numLine, a, b, w;
	cin >> numCase;
	while (numCase--)
	{
		cin >> N >> E >> T >> numLine;
		for (int i = 1; i <= N; i++)
		{
			dis[i] = -1;
			maze[i].clear();
			for (int j = 1; j <= N; j++)
			{
				weight[i][j] = 0;
			}
		}
		while (numLine--)
		{
			cin >> a >> b >> w;
			maze[b].push_back(a);
			weight[b][a] = w;
		}
		cout << bfs(N, E, T) << "\n";
		if (numCase != 0)
		{
			cout << "\n";
		}
	}

	return 0;
}