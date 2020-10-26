#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <queue>
#include <algorithm>

using namespace std;

const int rangeConst = 50;

int main() {
	int cap[rangeConst][rangeConst] = {}, flow[rangeConst][rangeConst] = {};
	int num = 0, indexApp, indexComp, sum = 0, f = 0;
	int ans[15];
	string line, result;
	while (getline(cin, line) || cin.eof())
	{
		if (line == "" || cin.eof())
		{
			result = "__________";
			for (int i = 27; i < 37; i++)
			{
				cap[i][i + 10] += 1;
				cap[i + 10][rangeConst - 1] += 1000000;
			}
			while (true)
			{
				int pre[rangeConst];
				int a[rangeConst];
				memset(pre, -1, sizeof(pre));
				memset(a, 0, sizeof(a));
				a[0] = 1000000;
				queue<int>q;
				q.push(0);
				while (!q.empty())
				{
					int u = q.front();
					q.pop();
					for (int i = 1; i < rangeConst; i++)
					{
						if (cap[u][i] > flow[u][i] && !a[i])
						{
							pre[i] = u;
							q.push(i);
							a[i] = min(a[u], cap[u][i] - flow[u][i]);
						}
					}
				}
				if (a[rangeConst - 1] == 0)
				{
					break;
				}
				for (int i = rangeConst - 1; i != 0; i = pre[i])
				{
					if (i < 37 && i > 26 && pre[i] != -1)
					{
						result[i - 27] = char(pre[i] + 'A' - 1);
					}
					flow[pre[i]][i] += a[rangeConst - 1];
					flow[i][pre[i]] -= a[rangeConst - 1];
				}
				f += a[rangeConst - 1];
			}
			if (f >= sum)
			{
				for (int i = 0; i < result.size(); i++)
				{
					cout << result[i];
				}
				cout << "\n";

			}
			else
			{
				cout << "!\n";
			}
			memset(flow, 0, sizeof(flow));
			memset(cap, 0, sizeof(cap));
			sum = f = 0;
			if (cin.eof())
			{
				break;
			}
		}
		else
		{
			indexApp = line[0] - 'A' + 1;
			num = line[1] - '0';
			sum += num;
			cap[0][indexApp] = num;
			for (int i = 3; i < line.size() - 1; i++)
			{
				indexComp = line[i] - '0' + 27;
				cap[indexApp][indexComp] += 1;
			}
		}
	}
	return 0;
}