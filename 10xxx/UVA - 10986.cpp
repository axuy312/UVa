#include <iostream>
#include <queue>

using namespace std;
int weight[20001][20001], dis[20001];
vector<int>connect[20001];

struct Node
{
	int d, w;
	bool operator<(const Node& node)const {
		return w > node.w;
	}
};

void bfs(int s, int t) {
	priority_queue<Node>que;
	Node u, v;
	dis[s] = u.w = 0;
	u.d = s;
	que.push(u);
	while (!que.empty())
	{
		u = que.top();
		que.pop();
		if (u.d == t)
		{
			return;
		}
		for (int i = 0; i < connect[u.d].size(); i++)
		{
			if (dis[connect[u.d][i]] > u.w + weight[u.d][connect[u.d][i]] || dis[connect[u.d][i]] == -1)
			{
				v.w = dis[connect[u.d][i]] = u.w + weight[u.d][connect[u.d][i]];
				v.d = connect[u.d][i];
				que.push(v);
			}
		}
	}
}

int main() {
	int N, n, m, S, T, u, v, w;
	bool repeat;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> n >> m >> S >> T;
		for (int j = 0; j < n; j++)
		{
			connect[j].clear();
			dis[j] = -1;
		}
		for (int j = 0; j < m; j++)
		{
			cin >> u >> v >> w;
			repeat = false;
			for (int k = 0; k < connect[u].size(); k++)
			{
				if (connect[u][k] == v)
				{
					repeat = true;
					if (w < weight[u][connect[u][k]])
					{
						weight[u][v] = weight[v][u] = w;
					}
					break;
				}
			}
			if (!repeat)
			{
				weight[u][v] = weight[v][u] = w;
				connect[u].push_back(v);
				connect[v].push_back(u);
			}
		}
		bfs(S, T);
		cout<< "Case #" << i << ": ";
		if (dis[T] == -1)
		{
			cout<< "unreachable\n";
		}
		else
		{
			cout<< dis[T] << "\n";
		}
	}
	return 0;
}