#include <iostream>
#include <queue>

using namespace std;
int maze[1001][1001], path[1001][1001];
struct vetex
{
	int x, y, d;
	bool operator< (const vetex& v)const {
		return v.d < d;
	}
};

bool compare(int ud, int vd, int w) {
	if (vd == -1)
	{
		return true;
	}
	else if (ud != -1 && ud + w < vd)
	{
		return true;
	}
	return false;
}

int bfs(int n, int m) {
	priority_queue<vetex>que;
	vetex v, u;
	u.x = u.y = 0;
	u.d = path[0][0] = maze[0][0];
	que.push(u);

	while (!que.empty())
	{
		u = que.top();
		//cout << ux << " " << uy << " -> ";
		que.pop();
		if (n - 1 == u.x && m - 1 == u.y)
		{
			return path[u.x][u.y];
		}
		if (u.x + 1 < n && compare(u.d, path[u.x + 1][u.y], maze[u.x + 1][u.y]))
		{
			v.x = u.x + 1;
			v.y = u.y;
			path[u.x + 1][u.y] = v.d = path[u.x][u.y] + maze[u.x + 1][u.y];
			que.push(v);
		}
		if (u.x - 1 >= 0 && compare(u.d, path[u.x - 1][u.y], maze[u.x - 1][u.y]))
		{
			v.x = u.x - 1;
			v.y = u.y;
			path[u.x - 1][u.y] = v.d = path[u.x][u.y] + maze[u.x - 1][u.y];
			que.push(v);
		}
		if (u.y + 1 < m && compare(u.d, path[u.x][u.y + 1], maze[u.x][u.y + 1]))
		{
			v.x = u.x;
			v.y = u.y + 1;
			path[u.x][u.y + 1] = v.d = path[u.x][u.y] + maze[u.x][u.y + 1];
			que.push(v);
		}
		if (u.y - 1 >= 0 && compare(u.d, path[u.x][u.y - 1], maze[u.x][u.y - 1]))
		{
			v.x = u.x;
			v.y = u.y - 1;
			path[u.x][u.y - 1] = v.d = path[u.x][u.y] + maze[u.x][u.y - 1];
			que.push(v);
		}
	}
	return -1;
}

int main() {
	int N, M, numCase;
	cin >> numCase;
	while (numCase--)
	{
		cin >> N >> M;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				cin >> maze[i][j];
				path[i][j] = -1;
			}
		}
		cout << bfs(N, M);
		cout << "\n";
	}

	return 0;
}