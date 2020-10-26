#include <iostream>
#include <queue>

using namespace std;
bool bombs[1001][1001], vis[1001][1001];
int dis[1001][1001];


int bfs(int ux, int uy, int vx, int vy, int r, int c) {
	queue<int>qx, qy;
	qx.push(ux);
	qy.push(uy);
	vis[ux][uy] = true;

	while (!qx.empty())
	{
		ux = qx.front();
		uy = qy.front();
		//cout << ux << " " << uy << " -> ";
		qx.pop();
		qy.pop();
		if (ux == vx && uy == vy)
		{
			return dis[ux][uy];
		}
		if (ux + 1 < r && !vis[ux + 1][uy] && !bombs[ux + 1][uy])
		{
			qx.push(ux + 1);
			qy.push(uy);
			vis[ux + 1][uy] = true;
			dis[ux + 1][uy] = dis[ux][uy] + 1;
		}
		if (ux - 1 >= 0 && !vis[ux - 1][uy] && !bombs[ux - 1][uy])
		{
			qx.push(ux - 1);
			qy.push(uy);
			vis[ux - 1][uy] = true;
			dis[ux - 1][uy] = dis[ux][uy] + 1;
		}
		if (uy + 1 < c && !vis[ux][uy + 1] && !bombs[ux][uy + 1])
		{
			qx.push(ux);
			qy.push(uy + 1);
			vis[ux][uy + 1] = true;
			dis[ux][uy + 1] = dis[ux][uy] + 1;
		}
		if (uy - 1 >= 0 && !vis[ux][uy - 1] && !bombs[ux][uy - 1])
		{
			qx.push(ux);
			qy.push(uy - 1);
			vis[ux][uy - 1] = true;
			dis[ux][uy - 1] = dis[ux][uy] + 1;
		}
	}
	return -1;
}

int main() {
	int R, C, rows, numRow, numBomb, pos, startX, startY, endX, endY;
	while (cin >> R >> C)
	{
		if (R == 0 && C == 0)
		{
			break;
		}
		cin >> rows;
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				bombs[i][j] = vis[i][j] = false;
				dis[i][j] = 0;
			}
		}
		//create bomb map
		while (rows--)
		{
			cin >> numRow >> numBomb;
			while (numBomb--)
			{
				cin >> pos;
				bombs[numRow][pos] = true;
			}
		}

		//debug
		/*for (int i = 0; i < R; i++)
		{
			cout << i << ":";
			for (int j = 0; j < C; j++)
			{
				cout << " " << bombs[i][j];
			}
			cout << "\n";
		}*/

		cin >> startX >> startY >> endX >> endY;
		cout << bfs(startX, startY, endX, endY, R, C) << "\n";
	}

	return 0;
}