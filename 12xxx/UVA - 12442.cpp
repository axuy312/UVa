#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

vector<int>connect;
vector<int>emailcount;
vector<bool>check;
vector<int>circle;
int dfs(int index) {
	if (connect[index] != 0 && !check[connect[index]])
	{
		check[index] = true;
		circle.push_back(index);
		int add = dfs(connect[index]);
		if (!circle.empty() && circle[circle.size() - 1] == index)
		{
			emailcount[index] = add + 1;
			circle.pop_back();
		}
		else
		{
			emailcount[index] = add;
		}
		//cout << index << " -> " << connect[index] << " : " << emailcount[index] << "\n";
		return emailcount[index];
	}
	else if (check[connect[index]])
	{
		int count = 0, pop;
		bool exist = false;
		for (int i = circle.size() - 1; i >= 0; i--)
		{
			count++;
			if (circle[i] == connect[index])
			{
				exist = true;
				break;
			}
		}
		check[index] = true;
		if (exist)
		{
			emailcount[index] = count;
			while (count--)
			{
				circle.pop_back();
			}
		}
		else
		{
			emailcount[index] = emailcount[connect[index]] + 1;
		}
		//cout << index << " -> " << connect[index] << " : " << emailcount[index] << "\n";
		return emailcount[index];
	}
	return 0;
}

int main() {
	int numcase, numconnect, u, v, max = 0, num;
	cin >> numcase;
	for (int i = 0; i < numcase; i++)
	{
		cin >> numconnect;
		max = num = 0;
		connect.clear();
		connect.resize(numconnect + 1);
		emailcount.clear();
		emailcount.resize(numconnect + 1);
		for (int k = 1; k <= numconnect; k++)
		{
			cin >> u >> v;
			connect[u] = v;
		}
		check.clear();
		check.resize(numconnect + 1);
		for (int j = 1; j <= numconnect; j++)
		{
			if (!check[j])
			{
				emailcount[j] = dfs(j);
			}
		}
		for (int j = 1; j <= numconnect; j++)
		{
			/*bool vis[300] = {};
			int cur = j;
			do
			{
				vis[cur] = true;
				cout << setw(3) << cur << "->";
				cur = connect[cur];
			} while (cur != 0 && !vis[cur]);
			cout << "Size: " << emailcount[j];
			cout << "\n";*/
			if (max < emailcount[j])
			{
				max = emailcount[j];
				num = j;
			}
			else if (max == emailcount[j] && j < num)
			{
				num = j;
			}
		}
		cout << "Case " << i + 1 << ": " << num << '\n';
	}
	system("pause");
	return 0;
}