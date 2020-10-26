#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>>connect;
vector<int>connected;
vector<int>order;


void dfs(int len) {
	if (len == connected.size())
	{
		cout << order[0];
		for (int i = 1; i < order.size(); i++)
		{
			cout << " " << order[i];
		}
		cout << "\n";
	}
	for (int i = connected.size() - 1; i >= 0; i--)
	{
		if (connected[i] == 0)
		{
			connected[i]--;
			order.push_back(i);
			for (int j = 0; j < connect[i].size(); j++)
			{
				connected[connect[i][j]]--;
			}
			dfs(len + 1);
			break;
		}
	}
}

int main() {
	int n, m, x, y;
	while (cin >> n >> m)
	{
		if (m == 0 && n == 0)
		{
			break;
		}
		connect.clear();
		connect.resize(n + 1);
		connected.clear();
		connected.resize(n + 1);
		order.clear();
		while (m--)
		{
			cin >> x >> y;
			connect[x].push_back(y);
			connected[y]++;
		}
		dfs(1);
	}
	system("pause");
	return 0;
}