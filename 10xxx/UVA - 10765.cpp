#include <iostream>
#include <vector>

using namespace std;

struct node
{
	int count;
	int num;
	int min;
	int pre;
};

void dfs(vector<vector<int>>&railway, vector<node>&station, int u, int &time) {
	station[u].num = station[u].min = ++time;
	for (int i = 0; i < railway[u].size(); i++)
	{
		if (station[railway[u][i]].num == 0)
		{
			station[u].count++;
			station[railway[u][i]].count++;
			station[railway[u][i]].pre = u;
			//cout << u << " -> " << railway[u][i] << " : " << station[u].count << endl;
			dfs(railway, station, railway[u][i], time);
			if (station[railway[u][i]].min <= station[u].min)
			{
				station[u].min = station[railway[u][i]].min;
			}
			if (station[railway[u][i]].min < station[u].num)
			{
				station[u].count--;
			}
		}
		else if (station[u].pre != railway[u][i])
		{
			if (station[railway[u][i]].num < station[u].min)
			{
				station[u].min = station[railway[u][i]].num;
			}
		}
	}

}

int main() {
	int n, m, x, y, numBomb, time;
	vector<vector<int>>railway;
	vector<node>station;
	while (cin >> n >> m)
	{
		if (n == 0 && m == 0)
		{
			break;
		}
		time = 0;
		railway.clear();
		railway.resize(n);
		station.clear();
		station.resize(n);
		while (cin >> x >> y)
		{
			if (x == -1 && y == -1)
			{
				break;
			}
			railway[x].push_back(y);
			railway[y].push_back(x);
		}
		dfs(railway, station, 0, time);
		while (m--)
		{
			int max = 0, index = 0;
			for (int i = 0; i < station.size(); i++)
			{
				//cout << i << " " << station[i].count << '\n';
				if (station[i].count > max)
				{
					max = station[i].count;
					index = i;
				}
			}
			cout << index << " " << station[index].count << '\n';
			station[index].count = 0;
		}
		cout << '\n';
	}
	system("pause");
	return 0;
}