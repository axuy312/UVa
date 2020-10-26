#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
struct Monkey
{
	int a, b, v;
};
struct Time
{
	int m;
};
int main() {
	int n, m, v, a, b;
	Monkey monkey[101];
	vector<Time>time;
	while (cin >> n)
	{
		if (!n)
		{
			break;
		}
		int region[50001];
		int cnt = 0, nCnt = 1;
		cin >> m;
		time.clear();
		for (int i = 0; i < n; i++)
		{
			cin >> v >> a >> b;
			monkey[i].a = a;
			monkey[i].b = b;
			monkey[i].v = v;
			region[cnt++] = a;
			region[cnt++] = b;
		}
		sort(region, region + cnt);
		for (int i = 1; i < cnt; i++)
		{
			if (region[i] != region[nCnt])
			{
				region[nCnt++] = region[i];
			}
		}
		cnt = nCnt;
		for (int i = 0; i < 50001; i++)
		{
			if (time[i].monkey.empty())
			{
				continue;
			}
			cout << i << ":";
			for (int j = 0; j < time[i].monkey.size(); j++)
			{
				cout << " " << monkey[i].connect[j];
			}
			cout << "\n";
		}
		for (int i = 0; i < n; i++)
		{
			cout << i << "(  " << monkey[i].a << " - " << monkey[i].b << " ):";
			for (int j = 0; j < monkey[i].connect.size(); j++)
			{
				cout << " " << monkey[i].connect[j];
			}
			cout << "\n";
		}
	}
	return 0;
}