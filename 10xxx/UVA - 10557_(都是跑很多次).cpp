#include <iostream>
#include <queue>
//#include <fstream>

using namespace std;

int energy[101], room[101][101], dis[101];

bool bfs(int n) {
	queue<int>Q;
	bool inQ[101] = {false};
	int c = 1,u;
	Q.push(1);
	while (!Q.empty())
	{
		u = Q.front();
		Q.pop();
		//cout << u << ":\n";
		inQ[u] = false;
		for (int i = 1; i <= room[u][0]; i++)
		{
			//cout << room[u][i] << " -- " << dis[room[u][i]] << " " << energy[room[u][i]] << " + " << dis[u] << "\n";
			if (dis[room[u][i]] < energy[room[u][i]] + dis[u])
			{
				if (!inQ[room[u][i]])
				{
					inQ[room[u][i]] = true;
					Q.push(room[u][i]);
					c++;
				}
				dis[room[u][i]] = energy[room[u][i]] + dis[u];
			}
		}
		//cout << "\n";
		if (dis[n] > 0)
			return true;
		if (c > 10000*n)
			return false;
	}
	return false;
}

int main() {
	//ofstream out("t.txt");
	int n;
	while (cin >> n && n != -1)
	{
		for (int i = 1; i <= n; i++)
		{
			dis[i] = 0;
			cin >> energy[i] >> room[i][0];
			for (int j = 1; j <= room[i][0]; j++)
			{
				cin >> room[i][j];
			}
		}
		dis[1] = 100;
		if (!bfs(n))
		{
			cout << "hopeless\n";
		}
		else
		{
			cout << "winnable\n";
		}
	}
	//system("pause");
	return 0;
}