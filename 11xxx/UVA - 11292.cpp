#include <iostream>
#include <algorithm>

using namespace std;


int main() {
	int n, m, h, cost;
	bool find;
	int dragon[20005], knight[20005];
	while (cin >> n >> m)
	{
		if (!n && !m)
		{
			break;
		}
		cost = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> dragon[i];
		}
		for (int i = 0; i < m; i++)
		{
			cin >> knight[i];
		}
		sort(dragon, dragon + n);
		sort(knight, knight + m);
		for (int i = 0; i < n; i++)
		{
			find = false;
			for (int j = 0; j < m; j++)
			{
				if (knight[j] >= dragon[i])
				{
					cost += knight[j];
					knight[j] = -1;//ÁôÂÃ´ú¸ê0
					find = true;
					break;
				}
			}
			if (!find)
			{
				break;
			}
		}
		if (find)
		{
			cout << cost << "\n";
		}
		else
		{
			cout << "Loowater is doomed!\n";
		}
	}
	return 0;
}