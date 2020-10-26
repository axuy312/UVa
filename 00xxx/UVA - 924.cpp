#include <iostream>
#include <queue>

using namespace std;
int numEmployee;
vector<int>contact[3000];

void bfs(int u) {
	vector<int>numLevel(numEmployee), dis(numEmployee);
	vector<bool>vis(numEmployee);
	queue<int>que;
	int max = 0, day;

	que.push(u);
	vis[u] = true;
	dis[u] = 0;
	numLevel[0]++;

	while (!que.empty())
	{
		u = que.front();
		que.pop();
		for (int i = 0; i < contact[u].size(); i++)
		{
			if (!vis[contact[u][i]])
			{
				vis[contact[u][i]] = true;
				que.push(contact[u][i]);
				dis[contact[u][i]] = dis[u] + 1;
				
				if (++numLevel[dis[contact[u][i]]] > max)
				{
					max = numLevel[dis[contact[u][i]]];
					day = dis[contact[u][i]];
				}
			}
		}
	}
	cout << max;
	if (max)
	{
		cout << " " << day;
	}
	cout << "\n";

}

int main() {
	int numline, num, id;
	
	cin >> numEmployee;
	for (int k = 0; k < numEmployee; k++)
	{
		cin >> num;
		contact[k].clear();
		while (num--)
		{
			cin >> id;
			contact[k].push_back(id);
		}
	}

	//debug
	/*for (int i = 0; i < numEmployee; i++)
	{
		cout << i << ":";
		for (int j = 0; j < contact[i].size(); j++)
		{
			cout << " " << contact[i][j];
		}
		cout << "\n";
	}*/
	//system("pause");
	//

	cin >> numline;
	while (numline--)
	{
		cin >> id;
		bfs(id);
	}


	return 0;
}